#include <random>
#include <iterator>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <utility>

std::random_device device;
std::mt19937 generator(device());

template <typename T>
T randInt(int min, int max){
    assert(min <= max);
    std::uniform_int_distribution<T> rd(min, max);
    return rd(generator);
}

std::vector <int> randomSample(std::vector <int> pickArray, int K){
    std::vector <int> ans;
    std::sample(pickArray.begin(), pickArray.end(), back_inserter(ans), K,
       std::mt19937{std::random_device{}()});
    return ans;
}

std::string randomDate(int minYear, int maxYear){
    int m_day = randInt<int>(0, 28);
    int m_month = randInt<int>(1, 12);
    int m_year = randInt<int>(minYear, maxYear);

    std::string day = std::to_string(m_day);
    std::string month = std::to_string(m_month);
    std::string year = std::to_string(m_year);

    while(day.length() < 2)
        day = '0' + day;

    while(month.length() < 2)
        month = '0' + month;
    
    return day + "/" + month + "/" + year;
}