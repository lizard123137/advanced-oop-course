#include <iostream>
#include <vector>
#include <set>
#include <utility>

// 5.1
std::pair<int, int> getRepeat(std::vector<int> v) {
	std::set<int> dict {};

	int repeating = -1;
	int sum = 0;

	for(auto& el : v) {
		std::cout << "Current element is: " << el << std::endl;
		if (!dict.insert(el).second)
			repeating = el;
		else
			sum += el;
	}

	return std::make_pair(repeating, sum - repeating);
}

int main() {
	// 5.1
	std::vector<int> test = { 5, 3, 2, 1, 1, 6 };

	auto res = getRepeat(test);
	std::cout << "Repeating element: " 
		<< res.first << "\n"
		<< "Sum of unique: "
		<< res.second << std::endl;

	return EXIT_SUCCESS;
}
