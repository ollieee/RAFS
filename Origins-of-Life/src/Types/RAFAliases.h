//
// Created by Oliver Weller-Davies on 14/12/2018.
//

#ifndef ORIGINS_OF_LIFE_RAFALIASES_H
#define ORIGINS_OF_LIFE_RAFALIASES_H

#include <unordered_set>
#include <unordered_map>
#include <set>
#include <iostream>

// Parametrized type aliases
namespace raf {

    // Representing std::unordered_set<T> as uset
    template<typename T>
    using uset = std::unordered_set<T>;

    // Representing std::unordered_map<T> as umap
    template<typename T, typename U>
    using umap = std::unordered_map<T, U>;

}

// A set of random helper functions
namespace raf {

    // Prints all values of an iterable (aggregate) type
    template <typename Iterable>
    void printIterable (const Iterable & ts, std::ostream & str = std::cout) {
        for (const auto & t : ts) {
            std::cout << t << " ";
        }
        std::cout << std::endl;
    }

    // Determines whether one set is a subset of another S1 <= S2
    template <typename T>
    bool isSubset (const uset<T> & S1, const uset<T> & S2) {
        for (const auto & x : S1) {
            if (S2.find(x) == S2.end()) {
                return false;
            }
        }
        return true;
    }

    // Unionise two sets; return the union in the second argument
    template <typename T>
    void unioniseSets (const uset<T> & S1, uset<T> & S2) {
        for (const auto x : S1) {
            S2.insert(x);
        }
    }
}


#endif //ORIGINS_OF_LIFE_RAFALIASES_H
