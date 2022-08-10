#include <bits/stdc++.h>
using namespace std;

// do not modify this function
void readFiles(char** argv){
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
}

int main(int argc, char** argv){
    readFiles(argv);

    // your main solution goes here
    int n;
    cin >> n;
    cout << n + 1 << '\n';
}