CC = g++
VER = c++17

all: run.cpp sol.cpp codegen.h
	$(CC) -std=$(VER) -g -o sol sol.cpp
	$(CC) -std=$(VER) -g -o main run.cpp

clean:
	rm -f *.o
	rm main
	rm sol