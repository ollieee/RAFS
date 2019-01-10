//
// Created by Oliver Weller-Davies on 11/12/2018.
//

#ifndef ORIGINS_OF_LIFE_RAFS_H
#define ORIGINS_OF_LIFE_RAFS_H

#include "RAF.h"

namespace raf {

    template <typename mID_t, typename rID_t>
    class RAFSolver1 : public AbstractRAFSolver<mID_t, rID_t> {

    public:

        void findMaxRAF (const raf::FoodCRS <mID_t, rID_t> & crs, uset <rID_t> & rafBuild) override {

            // Names of reactions still possibly in the maxRAF
            for (auto p : crs.reactions) {
                rafBuild.insert(p.first);
            }

            bool hitFixedPoint = false;
            while (!hitFixedPoint) {
                hitFixedPoint = true;

                // Molecule closure from food set starts at food set
                uset <mID_t> molClosure = crs.foodSet;

                // Reset reaction closure
                uset <rID_t> rClosure;

                bool canExpand = true;
                while (canExpand) {
                    canExpand = false;
                    for (auto rName : rafBuild) {

                        // If we have not already inserted this reaction in the closure
                        if (rClosure.find(rName) == rClosure.end()) {
                            auto reaction = crs.reactions.at(rName);

                            /* If the reactants are a subset of the current moleculeClosure, we know to include this
                               reaction in rafBuild. */
                            if (isSubset(reaction->getReactants(), molClosure)) {
                                rClosure.insert(rName);
                                unioniseSets(reaction->getProducts(), molClosure);
                                canExpand = true;
                            }
                        }
                    }
                }

                rafBuild = std::move(rClosure); // reaction closure (deletes starved reactions)

                /* Now molClosure should represent cl(rafBuild)(F); remove all uncatalyzed reactions */
                for (auto rName : rafBuild) {
                    auto reaction = crs.reactions.at(rName);
                    // If the reaction is uncatalyzed, remove it
                    bool isCatalyzed = false;
                    for (auto catalyzer : reaction->getCatalyzers()) {
                        if (molClosure.find(catalyzer) != molClosure.end()) {
                            isCatalyzed = true;
                            break;
                        }
                    }
                    if (!isCatalyzed) {
                        rafBuild.erase((rafBuild.find(rName)));
                        hitFixedPoint = false;
                        break;
                    }
                }
            }
        }

    };

}

#endif //ORIGINS_OF_LIFE_RAFS_H
