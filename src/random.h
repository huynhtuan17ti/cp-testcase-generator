#include <random>
#include <iterator>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <utility>

std::random_device device;
std::mt19937 generator(device());

template <typename T>
struct RandomPair{
    T min, max;
    RandomPair(int minValue, int maxValue){
        assert(minValue <= maxValue);
        min = minValue;
        max = maxValue;
    }
    RandomPair(int value){
        min = max = value;
    }
    T get(){
        std::uniform_int_distribution<T> rd(lo, hi);
        return rd(generator);
    }
};

std::vector <int> randomSample(std::vector <int> pickArray, int K){
    std::vector <int> ans;
    std::sample(pickArray.begin(), pickArray.end(), back_inserter(ans), K,
       std::mt19937{std::random_device{}()});
    return ans;
}