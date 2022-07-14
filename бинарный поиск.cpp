#include <iostream>
#include <random>
#include <vector>

using std::cout; using std::vector;
using std::endl;

constexpr int MIN = 1;
constexpr int MAX = 1000;
constexpr int NUMS_TO_GEN = 1000;

template<typename T>
int binarySearch(const vector<T>& vec, T& item, int s1, int s2) {
    if (s1 > s2)
        return -1;

    auto middle = (s1 + s2) / 2;

    if (item == vec.at(middle))
        return middle;

    if (item > vec.at(middle))
        return binarySearch(vec, item, middle + 1, s2);
    else
        return binarySearch(vec, item, s1, middle - 1);
}

template<typename T>
int searchVector(const vector<T>& vec, T& item) {
    return binarySearch(vec, item, 0, vec.size() - 1);
}

int main() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);

    std::vector<int> vec;
    vec.reserve(NUMS_TO_GEN);
    for (int n = 0; n < NUMS_TO_GEN; ++n) {
        vec.push_back(distr(eng));
    }
    std::sort(vec.begin(), vec.end());

    std::vector<int> vec2{ 2, 111, 222, 5, 333, 7, 8, 444, 100 };
    for (auto& item : vec2) {
        searchVector(vec, item) != -1 ?
            cout << "found, " :
            cout << "did not, ";
    }
    cout << endl;

    for (auto& item : vec2) {
        std::find(vec.begin(), vec.end(), item) != vec.end() ?
            cout << "found, " :
            cout << "did not, ";
    }

    return EXIT_SUCCESS;
}
