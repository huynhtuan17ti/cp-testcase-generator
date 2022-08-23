#include "generator.h"
using namespace std;

int main(int argc, char** argv){
    int num_test_case = 10;
    if(argc == 3 && argv[1] == string("-N")){
        num_test_case = stoi(argv[2]);
        testGenerator(num_test_case);
    }
    else if(argc == 2 && argv[1] == string("-temp")){
        system("cp /usr/bin/gen_temp/rand.cpp rand.cpp");
        system("cp /usr/bin/gen_temp/random.h random.h");
    }else{
        throw("The syntax is not true.");
    }
}