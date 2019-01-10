//
// Created by Oliver Weller-Davies on 14/12/2018.
//

#ifndef ORIGINS_OF_LIFE_FOODCRS_H
#define ORIGINS_OF_LIFE_FOODCRS_H

#include "Reaction.h"
#include "RAFAliases.h"

/* FoodCRS represents a Chemical Reaction System with a designated Food Set.
   The types moleculeId_t and reactionId_t are the types of the 'ids' of the molecules / reactions.
   They must be comparable for equality. */

namespace raf {

    template <typename mID_t, typename rID_t>
    struct FoodCRS {

        typedef Reaction <mID_t, rID_t> CRSReaction; // CLion doesn't like generics here.

        // Representing sets of molecules as unordered sets; reactions as a map (cannot hash primitives)
        uset <mID_t> molecules;                // -- X
        uset <mID_t> foodSet;                  // -- F
        umap <rID_t, CRSReaction *> reactions; // -- R

        // Initialise as empty
        explicit FoodCRS() = default;;

        // Initialise by passing in the molecules, reaction and food set as above
        explicit FoodCRS (uset <mID_t> molecules, uset <mID_t> foodSet, umap <rID_t, CRSReaction * > & reactions)
            : molecules(molecules), foodSet(foodSet), reactions(reactions) {
            // Just double check that the foodSet is a subset of the molecule set
            assert(isSubset(foodSet, molecules));
        }

        void print (std::ostream & str = std::cout) const {
            str << "CRS Print:" << "\n";
            str << "Molecules: ";
            printIterable(molecules, str);
            str << "Food Set: ";
            printIterable(foodSet, str);
            for (auto p : reactions) {
                (p.second)->print(str);
            }
        }

    };

}

#endif //ORIGINS_OF_LIFE_FOODCRS_H
