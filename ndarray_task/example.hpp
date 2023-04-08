#include <iostream>
#include "NDArray.h"

void empty(){
    std::cout << "The default constructor creates an empty array of the specified size: 5x5" << std::endl;
    NDArray<int> arr({5, 5});
    std::cout << arr << std::endl;
}

void zeros(){
    std::cout << "Creating a 2x2 array filled with fill_zeros" << std::endl;
    auto arr = NDArray<int>::zeros({2, 2});
    std::cout << arr << std::endl;
}

void ones(){
    std::cout << "Creating a 2x2 array filled with fill_ones" << std::endl;
    auto arr = NDArray<int>::ones({2, 2});
    std::cout << arr << std::endl;
}

void randomInt(){
    std::cout << "Creating a 2x2x2 array filled with random integer values" << std::endl;
    auto arr = NDArray<int>::random({2, 2, 2});
    std::cout << arr << std::endl;
}

void randomFloat(){
    std::cout << "Creating a 2x2x2 array filled with random float values" << std::endl;
    auto arr = NDArray<float>::random({2, 2, 2});
    std::cout << arr << std::endl;
}

void addition(){
    std::cout << "The element-by-element addition of 2 arrays" << std::endl;
    auto arr1 = NDArray<int>::random({3, 3});
    auto arr2 = NDArray<int>::ones({3, 3});
    auto arr3 = arr1 + arr2;
    std::cout << "arr1 = " << arr1 << std::endl;
    std::cout << "arr2 = " << arr2 << std::endl;
    std::cout << "result is " << arr3 << std:: endl;
}

void substruction(){
    std::cout << "The element-by-element subtraction of 2 arrays" << std::endl;
    auto arr1 = NDArray<int>::random({3, 3});
    auto arr2 = NDArray<int>::ones({3, 3});
    auto arr3 = arr1 - arr2;
    std::cout << "arr1 = " << arr1 << std::endl;
    std::cout << "arr2 = " << arr2 << std::endl;
    std::cout << "result is " << arr3 << std:: endl;
}

void multiply(){
    std::cout << "The element-by-element multiply of 2 arrays" << std::endl;
    auto arr1 = NDArray<int>::random({2, 2});
    auto arr2 = NDArray<int>::random({2, 2});
    auto arr3 = arr1 * arr2;
    std::cout << "arr1 = " << arr1 << std::endl;
    std::cout << "arr2 = " << arr2 << std::endl;
    std::cout << "result is " << arr3 << std:: endl;
}

void division(){
    std::cout << "The element-by-element division of 2 arrays" << std::endl;
    auto arr1 = NDArray<int>::random({2, 2});
    auto arr2 = NDArray<int>::random({2, 2});
    auto arr3 = arr1 / arr2;
    std::cout << "arr1 = " << arr1 << std::endl;
    std::cout << "arr2 = " << arr2 << std::endl;
    std::cout << "result is " << arr3 << std:: endl;
}

void matrixmultiply(){
    std::cout << "matrix multiplication of 2 arrays" << std::endl;
    auto arr1 = NDArray<int>::random({2, 2});
    auto arr2 = NDArray<int>::random({2, 2});
    auto arr3 = arr1.matmul(arr2);
    std::cout << "arr1 = " << arr1 << std::endl;
    std::cout << "arr2 = " << arr2 << std::endl;
    std::cout << "result is " << arr3 << std::endl;
}

void transposematrix(){
    std::cout << "matrix transposition" << std::endl;
    auto arr1 = NDArray<int>::random({4, 4});
    auto arr2 = arr1.transpose();
    std::cout << "arr1 = " << arr1 << std::endl;
    std::cout << "arr2 = " << arr2 << std::endl;
}

template <typename T>
void print_vec(const std::vector<T> &vec){
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void min(){
    auto arr = NDArray<int>::random({4, 4});
    auto minimum = arr.min();
    std::cout << arr << std::endl << "Minimum value of array: ";
    print_vec(minimum);
    std::cout << std::endl; 
}

void max(){
    std::cout << "the maximum value of each column" << std::endl;
    auto arr = NDArray<int>::random({4, 4});
    auto maximum = arr.max(0);
    std::cout << arr << std::endl << "Maximum value of each column: ";
    print_vec(maximum);
    std::cout << std::endl;
}

void average(){
    std::cout << "the average value of each row" << std::endl;
    auto arr = NDArray<int>::random({4, 4});
    auto mean = arr.mean(1);
    std::cout << arr << std::endl << "Mean value of each row: ";
    print_vec(mean);
    std::cout << std::endl;
}