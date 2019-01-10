//
// Created by Oliver Weller-Davies on 15/12/2018.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "RAF.h"
#include "RAFSolver1.h"
#include "TestCaseProcessor.h"

using namespace std;
using namespace raf;

typedef string mID_t;
typedef string rID_t;

int main () {

    TestCaseProcessor p = TestCaseProcessor();
    auto r = RAFSolver1<string, string>();
    cout << p.runTests(r, "./smallCases.txt") << endl;

}