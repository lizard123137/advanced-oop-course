#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

// 5.1
std::pair<int, int> getRepeat(std::vector<int> v) {
	std::unordered_set<int> dict {};

	int repeating = -1;
	int sum = 0;

	for(auto& el : v) {
		if (!dict.insert(el).second)
			repeating = el;
		else
			sum += el;
	}

	return std::make_pair(repeating, sum - repeating);
}

// 5.2
// The whole enable_if part is ment to only allow types that can be added
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
add_unique(std::unordered_set<T> a, std::unordered_set<T> b) {
    /**
     * What we are trying to do from a mathematical point of view
     * is finding the symmetric difference of two sets.
     * The c++ library algorithms has a function for that.
     * 
     * After that we just sum the resulting elements.
     */
    std::vector<T> sym_diff;

    std::set_symmetric_difference(
        a.begin(), a.end(),
        b.begin(), b.end(),
        std::back_inserter(sym_diff)
    );

    /**
     * We cannot initialize this, since we do not know what type it is.
     * C++ however is supposed to zero initialize variables, so let's hope it does its job...
     */
    T acc;

    for (auto &x : sym_diff) {
        acc += x;
    }

    return acc;
}

// 5.3
// This assignment tells us to assume the first string is longer by one char
char find_diff(std::string first, std::string second) {
    std::unordered_set<char> found;
    
    for(auto c : second) {
        found.insert(c);
    }

    for(auto c : first) {
        if(found.count(c) == 0)
            return c;
    }

    return 'F'; // Bad arguments: Press F to pay respect
}

int main() {
	// 5.1
	std::vector<int> test = { 5, 3, 2, 1, 1, 6 };

	auto res = getRepeat(test);
	std::cout << "5.1\n" 
        << "Repeating element: " 
		<< res.first << "\n"
		<< "Sum of unique: "
		<< res.second
        << std::endl;

    // 5.2
    std::unordered_set<int> a = { 0, 2, 4, 6, 8 };
    std::unordered_set<int> b = { 1, 2, 4, 6, 8 };

    std::cout << "5.2\n"
        << "The sum of unique elements is: "
        << add_unique(a, b)
        << std::endl;

    // 5.3
    std::string s1 = "testX";
    std::string s2 = "test";

    char c = find_diff(s1, s2);
    std::cout << "5.3\n"
        << "Unique char between the two strings is: "
        << c
        << std::endl;

	return EXIT_SUCCESS;
}
