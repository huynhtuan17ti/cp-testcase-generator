#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <functional>

const std::string testDir = "testcase";

void singleTestGenerator(int currentTest){
    std::string test = std::to_string(currentTest);
    if(test.size() == 1)
        test = '0' + test;
    
    std::cout << "Generating test " << test << " ..." << '\n';
    
    std::string inputFile = testDir + "/" + test + ".in";
    std::string outputFile = testDir + "/" + test + ".ans";
    system(("touch " + inputFile).c_str());

    system(("./gen > " + inputFile + " " + test).c_str());
    system(("./sol < " + inputFile + " > " + outputFile).c_str());
}

void testGenerator(int numTescase){
    system("g++ -std=c++17 -g -o gen rand.cpp");
    system("g++ -std=c++17 -g -o sol sol.cpp");

    namespace fs = std::filesystem;
    fs::remove_all(testDir);
    fs::create_directory(testDir)?
        std::cout << "created directory - " << testDir << '\n' :
        std::cout << "create_directory() failed" << '\n';

    for(int currentTest = 1; currentTest <= numTescase; currentTest++)
        singleTestGenerator(currentTest);

    system("rm gen sol");
}