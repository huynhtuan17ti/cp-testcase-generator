#include <fstream>
#include "src/random.h"

void genCode(std::fstream &inp, RandomPair<int> N){
    inp << N.get();
}

void randomTestcase(int test, std::fstream &inp){
    switch (test){
        case 0 ... 5:
            // test batch 1
            genCode(inp, {0, 10});
            break;
        case 6 ... 10:
            // test batch 2
            genCode(inp, {0, 100});
            break;
        
        default:
            throw ("The current testcase " + std::to_string(test) + " not in any cases.");
            break;
    }
}