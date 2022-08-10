#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <functional>

const std::string testDir = "testcase";

void singleTestGenerator(int currentTest, std::function<void(int, std::fstream&)> randomTestcase){
    std::string test = std::to_string(currentTest);
    if(test.size() == 1)
        test = '0' + test;
    
    std::cout << "Generating test " << test << " ..." << '\n';
    
    std::fstream inp;
    std::string inputFile = testDir + "/" + test + ".in";
    inp.open(inputFile, std::ios::out | std::ios::binary);

    std::ofstream out;
    std::string outputFile = testDir + "/" + test + ".ans";
    out.open(outputFile, std::ios::out | std::ios::binary);

    randomTestcase(currentTest, inp);

    inp.close();
    out.close();

    system(("./sol " + inputFile + " " + outputFile).c_str());
}

void testGenerator(int numTescase, std::function<void(int, std::fstream&)> randomTestcase){
    namespace fs = std::filesystem;
    fs::remove_all(testDir);
    fs::create_directory(testDir)?
        std::cout << "created directory - " << testDir << '\n' :
        std::cout << "create_directory() failed" << '\n';
    for(int currentTest = 1; currentTest <= numTescase; currentTest++)
        singleTestGenerator(currentTest, randomTestcase);
}