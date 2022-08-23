# cp-testcase-generator
An automatic test generator for competitive programming

## Install
```bash
    git clone https://github.com/huynhtuan17ti/cp-testcase-generator
    cd cp-testcase-generator
    make
    make install
```

## How to use
The template generator of this tool includes 2 files
```
--- your_dir
        | --- random.h # including some random functions
        | --- rand.cpp # the main file to generate testcases
```
To get the template, run.
```bash
    gentest temp
```

To generate testcases, your coding directory needs at least 2 files
```
--- your_dir
        | --- sol.cpp # the solution
        | --- rand.cpp # the file mentioned above
```

Run
```bash
    gentest -N number_of_test_case
``` 
to automatically create testcases.