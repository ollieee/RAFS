//
// Created by Oliver Weller-Davies on 14/12/2018.
//

#ifndef ORIGINS_OF_LIFE_REACTION_H
#define ORIGINS_OF_LIFE_REACTION_H

#include <unordered_set>
#include <unordered_map>
#include <iostream>

#include "RAFAliases.h"

// Reaction class
namespace raf {

    template <typename mID_t, typename rID_t>
    class Reaction {

    private:
        uset <mID_t> reactants;
        uset <mID_t> catalyzers;
        uset <mID_t> products;
        rID_t id;

    public:

        // Initialise only with reactionName
        explicit Reaction(const rID_t & id) : id(id) {}
        explicit Reaction(rID_t && id) : id(id) {}

        // Initialise in one go
        explicit Reaction(uset <mID_t> && reactants, uset <mID_t> catalyzers, uset<mID_t> products, rID_t id)
                : reactants(reactants), catalyzers(catalyzers), products(products), id(id) {}

        // Setters
        void setReactants (const uset <mID_t> & newReactants) {
            reactants = newReactants;
        }

        void setReactants (uset <mID_t> && newReactants) {
            reactants = newReactants;
        }

        void setCatalyzers (uset <mID_t> newCatalyzers) {
            catalyzers = newCatalyzers;
        }

        void setProducts (const uset <mID_t> & newProducts) {
            products = newProducts;
        }

        void setProducts (uset <mID_t> && newProducts) {
            products = newProducts;
        }

        // Incremental setters
        void addReactant (mID_t newReactant) {
            reactants.insert(newReactant);
        }

        void addCatalyzer (mID_t newCatalyzer) {
            catalyzers.insert(newCatalyzer);
        }

        void addProduct (mID_t newProduct) {
            products.insert(newProduct);
        }

        // Getters
        const uset <mID_t> & getReactants () {
            return reactants;
        }

        const uset <mID_t> & getCatalyzers () {
            return catalyzers;
        }

        const uset <mID_t> & getProducts () {
            return products;
        }

        rID_t getID () {
            return id;
        }

        // Helper functions
        void print (std::ostream & str = std::cout) {
            str << "Reaction " << id << ": ";
            for (auto r : reactants) {
                str << r << " ";
            }
            str << "--> ";
            for (auto p : products) {
                str << p << " ";
            }
            str << ":: catalyzed by ";
            for (auto c : catalyzers) {
                str << c << " ";
            }
            str << std::endl;
        }

    };

}

#endif //ORIGINS_OF_LIFE_REACTION_H
