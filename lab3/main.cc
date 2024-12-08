#include <iostream>
#include <string>

template<typename T>
T getMin(T arr[], size_t size) {
    if (size == 0) {
        std::cout << "Invalid size" << std::endl;
        exit(EXIT_FAILURE);
    }

    T temp = arr[0];
    for(size_t i = 0; i < size; i++) {
        if (arr[i] < temp)
            temp = arr[i];
    }

    return temp;
}

template<>
std::string getMin(std::string tab[], size_t size) {
    std::cout << "Invalid operation" << std::endl;
} 

int main(void) {
    // 3.2
    int arr1[] = {1, 5, 3, 2};
    std::cout << "Min of arr1: " << getMin(arr1, 4) << std::endl;

    float arr2[] = {1.0, 5.0, 0.5};
    std::cout << "Min of arr2: " << getMin(arr2, 3) << std::endl;


    return EXIT_SUCCESS;
}
