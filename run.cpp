#include "codegen.h"
#include "src/generator.h"
using namespace std;
const int NUM_TEST_CASE = 10;

int main(){
    testGenerator(NUM_TEST_CASE, &randomTestcase);
}