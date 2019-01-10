//
// Created by Oliver Weller-Davies on 14/12/2018.
//

#ifndef ORIGINS_OF_LIFE_RAF_H
#define ORIGINS_OF_LIFE_RAF_H

#include "RAFAliases.h"
#include "Reaction.h"
#include "FoodCRS.h"

namespace raf {
    // Interface for all maxRAF finders
    template <typename mID_t, typename rID_t>
    class AbstractRAFSolver {
    public:
        virtual void findMaxRAF (const raf::FoodCRS <mID_t, rID_t> & crs, uset <rID_t> & rafBuild) = 0;
    };
}

#endif //ORIGINS_OF_LIFE_RAF_H
