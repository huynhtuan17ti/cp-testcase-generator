#include "generator.h"
using namespace std;

int main(int argc, char** argv){
    int num_test_case = 10;
    if(argc == 3 && strcmp(argv[1], "-N") == 0){
        num_test_case = stoi((string)argv[2]);
        testGenerator(num_test_case);
    }
    else if(argc == 2 && strcmp(argv[1], "-temp") == 0){
        system("cp /usr/bin/gen_temp/rand.cpp rand.cpp");
        system("cp /usr/bin/gen_temp/random.h random.h");
    }else{
        throw("The syntax is not true.");
    }
}