#include <iostream>
#include <algorithm>
#include <list>
#include <random>
#include <deque>

class func_obj {
public:
    bool operator()(int x, int y) {
        int dig_sum_x = 0;
        int dig_sum_y = 0;

        while (x) {
            dig_sum_x += x % 10;
            x /= 10;
        }

        while (y) {
            dig_sum_y += y % 10;
            y /= 10;
        }

        return dig_sum_x > dig_sum_y;
    }
};

int main(void) {
    // 4.2
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(1, 20);

    int n = dist(mt);
    
    dist = std::uniform_int_distribution(-100, 100);

    std::vector<int> wylosowane = {};
    std::deque<int> posegregowane = {};

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

    struct obj {
	bool operator()(int x, int y) { return (x > y); }; 
    };

    // Three different ways of calling std::sort
    std::sort(posegregowane.begin(), posegregowane.end(), [](int x, int y) { return (x>y); });
    std::sort(posegregowane.begin(), posegregowane.end(), std::greater<int>());
    std::sort(posegregowane.begin(), posegregowane.end(), obj());

    std::for_each(posegregowane.begin(), posegregowane.end(), [](int x) { std::cout << x << ", "; });
    std::cout << std::endl;

    // 4.4
    std::vector<int> to_be_sorted_vec = { 0, 500, 3, 80, 1, 700, 2, 4, 6000, 9 };
    std::list<int> to_be_sorted_list = { 0, 55, 3, 8, 100, 7, 2, 4, 6, 99 };

    bool increasing = false;
    auto sort_func = [increasing](int x, int y) {
        return (increasing) ? ((int)log10(x) > (int)log10(y)) : ((int)log10(y) <= (int)log10(x));
    };

    std::sort(to_be_sorted_vec.begin(), to_be_sorted_vec.end(), sort_func);
    to_be_sorted_list.sort(func_obj());

    for (auto& x : to_be_sorted_vec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    for (auto& x : to_be_sorted_list) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
