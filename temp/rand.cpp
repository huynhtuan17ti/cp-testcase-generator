#include <bits/stdc++.h>
#include "random.h"

using namespace std;

void subtask1(){

}

void subtask2(){

}

int main(int argc, char** argv){
    int curTest = stoi(argv[1]);
    
    switch (curTest){
        case 0 ... 5:
            subtask1();
            break;
        case 6 ... 10:
            subtask2();
            break;
        
        // add more testcases here
        
        default:
            throw ("The current testcase " + std::to_string(curTest) + " not in any cases.");
            break;
    }
}