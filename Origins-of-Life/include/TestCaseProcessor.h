//
// Created by Oliver Weller-Davies on 16/12/2018.
//

#ifndef ORIGINS_OF_LIFE_TESTCASEPROCESSOR_H
#define ORIGINS_OF_LIFE_TESTCASEPROCESSOR_H

#include <string>
#include <fstream>
#include <sstream>

#include "RAF.h"

class TestCaseProcessor {

    /* Tests of the form: (look in smallCases.txt)
       Test 1:
       Molecules: f1 f2 f3 ...
       FoodSet: f1 f2 f3 p1 p3 ...
       Reactions:
       r1: f1 p3 -(p2)-> p4 p1
       r2: ...
       Expected: r1 r2 ...
       {blank line}

       To represent no products / expected reaction, you can use a semicolon to ensure that
       the space character does not get deleted upon save.
       */

    const std::string MString = "Molecules: ";
    const std::string FSString = "FoodSet: ";
    const std::string RString = "Reactions: ";
    const std::string EString = "Expected: ";

private:

    void getLine(std::fstream &f, std::string & line) {
        // Get line, skip over comments
        do {
            std::getline(f, line);
        } while (line[0] == '#');
    }

    // Splits a string up by char c and places in an unordered_set
    void splitToSet (const std::string & toSplit, raf::uset <std::string> & ret, char c) {
        std::stringstream sStream(toSplit);
        std::string str;
        ret.clear();
        while (getline(sStream, str, c)) {
            ret.insert(str);
        }
    }

    // Checks that str1 is a prefix of str2
    bool checkPrefix (const std::string & str1, const std::string & str2) {
        if (str1.size() > str2.size()) {
            return false;
        }
        for (int i = 0; i < (int) (str1.size()); i++) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }
        return true;
    }

    // Process the line describing the molecules; add each molecule to unordered_set ret
    void processMolLine (const std::string & molLine, raf::uset <std::string> & ret) {
        if (!checkPrefix(MString, molLine)) {
            throw std::runtime_error ("Incorrect formatting on Molecules");
        }
        // Now process CSV line
        std::string mols = molLine.substr(MString.size()); // Remove "Molecule: " from line
        splitToSet(mols, ret, ' ');
    }

    // Process the line describing food molecules; add each food molecule to unordered_set ret
    void processFoodLine (const std::string & foodLine, raf::uset <std::string> & ret) {
        if (!checkPrefix(FSString, foodLine)) {
            throw std::runtime_error ("Incorrect formatting on Food Set");
        }
        // Now process CSV line
        std::string food = foodLine.substr(FSString.size()); // Remove "FoodSet: " from line
        splitToSet(food, ret, ' ');
    }

    // Process a reaction line, add it to the unordered reaction map
    void processReactionLine (const std::string & reactLine, raf::umap <std::string,
            raf::Reaction <std::string, std::string> *> & ret) {

        // First, extract the name of the reaction
        std::string reactionName;
        bool foundName = false;
        int reactantStartIndex = 0;
        for (int i = 0; i < (int) reactLine.size() && !foundName; i++) {
            if (reactLine[i] == ':') {
                foundName = true;
                reactantStartIndex = i + 2; // +2 to skip over ": "
            } else {
                reactionName += reactLine[i];
            }
        }

        if (!foundName) {
            throw std::runtime_error("Incorrect formatting on Reaction line (name)");
        }

        auto * r = new raf::Reaction<std::string, std::string>(reactionName);

        // Extract reactants of the reaction
        std::string reactantName;
        bool foundReactant = false;
        int catalysisStartIndex = 0;
        for (int i = reactantStartIndex; i < (int) reactLine.size() && !foundReactant; i++) {
            if (reactLine[i] == '-') {
                foundReactant = true;
                catalysisStartIndex = i + 2; // +2 to skip over "-("
            } else if (reactLine[i] == ' ') {
                r->addReactant(reactantName);
                reactantName = "";
            } else {
                reactantName += reactLine[i];
            }
        }

        // Extract catalyzer
        std::string cataName;
        bool foundCatalyzer = false;
        int productStartIndex = 0;
        for (int i = catalysisStartIndex; i < (int) reactLine.size() && !foundCatalyzer; i++) {
            if (reactLine[i] != ')') {
                cataName += reactLine[i];
            } else {
                foundCatalyzer = true;
                productStartIndex = i + 4; // +4 to skip over ")-> "
            }
        }

        if (!foundCatalyzer) {
            throw std::runtime_error("Incorrect formatting on Reaction line (name)");
        }

        r->setCatalyzers({cataName});

        // Now process products
        std::string productName;
        for (int i = productStartIndex; i < (int) reactLine.size(); i++) {
            if (reactLine[i] == ' ' || reactLine[i] == ';') {
                r->addProduct(productName);
                productName = "";
            } else {
                productName += reactLine[i];
            }
        }
        if (!productName.empty()) {
            r->addProduct(productName);
        }

        ret[reactionName] = r;
    }

public:

    void processInputs(std::fstream &f, raf::FoodCRS<std::string, std::string> &crs,
                        raf::uset<std::string> & expectedResult) {
        raf::uset <std::string> molecules;
        raf::uset <std::string> foodSet;
        raf::umap <std::string, raf::Reaction<std::string, std::string> *> reactions;
        std::string line;
        getLine(f, line); processMolLine(line, molecules);
        getLine(f, line); processFoodLine(line, foodSet);
        getLine(f, line); // Reaction header
        if (!checkPrefix(RString, line)) {
            std::runtime_error("Reaction header incorrect");
        }
        // Process reactions
        getLine(f, line);
        while (!line.empty() && !checkPrefix(EString, line)) {
            processReactionLine(line, reactions);
            getLine(f, line);
        }
        // Extract expected result
        if (line.empty()) {
            std::runtime_error("Expected header incorrect");
        }
        // Now we must have Expected header:
        // If semicolon used as space-buffer, simply remove it.
        if (line[line.size() - 1] == ';') {
            line.erase(line.end() - 1);
        }
        splitToSet(line.substr(EString.size()), expectedResult, ' ');

        // Set crs
        crs.molecules = std::move(molecules);
        crs.foodSet = std::move(foodSet);
        crs.reactions = std::move(reactions);

        if (f.peek() != EOF) getline(f, line); // Test cases are line separated
    }

    bool runTests (raf::AbstractRAFSolver<std::string, std::string> & rafSolver,
                   const std::string & testPath, std::ostream &str = std::cout) {
        std::fstream f;
        f.open(testPath);
        if (!f.is_open()) {
            str << "Error opening test cases" << std::endl;
            return false;
        }
        raf::FoodCRS<std::string, std::string> crs;
        raf::uset<std::string> expectedResult;
        try {
            while (f.peek() != EOF) {

                processInputs(f, crs, expectedResult);
                raf::uset <std::string> result;
                crs.print();
                rafSolver.findMaxRAF(crs, result);
                str << "Expected: "; raf::printIterable(expectedResult, str);
                str << "Result: ";
                raf::printIterable(result, str);
                if (result == expectedResult) {
                    str << "TEST PASSED" << std::endl;
                } else {
                    str << "TEST FAILED" << std::endl;
                    return false;
                }
                str << std::endl;
            }
        } catch (std::exception &e) {
            str << e.what() << std::endl;
            return false;
        }

        return true;
    }

};

#endif //ORIGINS_OF_LIFE_TESTCASEPROCESSOR_H
