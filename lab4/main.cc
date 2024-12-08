#include <iostream>
#include <algorithm>
#include <random>
#include <list>

int main(void) {
    // 4.2
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(1, 10);

    int n = dist(mt);
    
    dist = std::uniform_int_distribution(-100, 100);

    std::vector<int> wylosowane = {};
    std::list<int> posegregowane = {};

    for(size_t i = 0; i < n; ++i) {
        wylosowane.push_back(dist(mt));
    }
    
    for(auto& el : wylosowane) {
        if (el >= 0)
            posegregowane.push_front(el);
        else
            posegregowane.push_back(el);
    }
    std::for_each(posegregowane.begin(), posegregowane.end(), [](int x) { std::cout << x << ", "; });
    std::cout << std::endl;

    return EXIT_SUCCESS;
}