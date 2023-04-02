#include <iostream>
#include "ndarray.h"

void emptyArray(){
    std::cout << "The default constructor creates an empty array of the specified size: 5x5" << std::endl;
    int shape[2] = {5, 5};
    NDArray<int> arr(2, shape);
}

void zerosArray(){
    std::cout << "Creating a 2x2 array filled with zeros" << std::endl;
    int shape[2] = {2, 2};
    NDArray<int> arr(2, shape);
    arr.zeros();
    arr.print();
}

void onesArray(){
    std::cout << "Creating a 2x2 array filled with ones" << std::endl;
    int shape[2] = {2, 2};
    NDArray<int> arr(2, shape);
    arr.ones();
    arr.print();
}

void randomIntArray(){
    std::cout << "Creating a 2x2x2 array filled with random integer values" << std::endl;
    int shape[3] = {2, 2, 2};
    NDArray<int> arr(3, shape);
    arr.random();
    arr.print();
}

void randomFloatArray(){
    std::cout << "Creating a 2x2x2 array filled with random float values" << std::endl;
    int shape[3] = {2, 2, 2};
    NDArray<float> arr(3, shape);
    arr.random();
    arr.print();
}

void addArrays(){
    std::cout << "The element-by-element addition of 2 arrays" << std::endl;
    int shape[2] = {4, 4};
    NDArray<int> arr1(2, shape);
    NDArray<int> arr2(2, shape);
    arr1.ones();
    arr2.ones();
    NDArray<int> arr3 = arr1 + arr2;
    arr3.print();
}

void subArrays(){
    std::cout << "The element-by-element subtraction of 2 arrays" << std::endl;
    int shape[2] = {4, 4};
    NDArray<int> arr1(2, shape);
    NDArray<int> arr2(2, shape);
    arr1.ones();
    arr2.ones();
    NDArray<int> arr3 = arr1 - arr2;
    arr3.print();
}

void mulArrays(){
    std::cout << "The element-by-element multiply of 2 arrays" << std::endl;
    int shape[2] = {4, 4};
    NDArray<int> arr1(2, shape);
    NDArray<int> arr2(2, shape);
    arr1.random();
    arr2.random();
    NDArray<int> arr3 = arr1 * arr2;
    arr3.print();
}

void divArrays(){
    std::cout << "The element-by-element division of 2 arrays" << std::endl;
    int shape[2] = {4, 4};
    NDArray<int> arr1(2, shape);
    NDArray<int> arr2(2, shape);
    arr1.ones();
    arr2.ones();
    NDArray<int> arr3 = arr1 / arr2;
    arr3.print();
}

void matmulArrays(){
    std::cout << "matrix multiplication of 2 arrays" << std::endl;
    int shape[2] = {2, 2};
    NDArray<int> arr1(2, shape);
    NDArray<int> arr2(2, shape);
    arr1.random();
    arr2.random();
    NDArray<int> arr3 = arr1.dot(arr2);
    arr3.print();
}

void transposeArray(){
    std::cout << "matrix transposition" << std::endl;
    int shape[2] = {3, 3};
    NDArray<int> arr(2, shape);
    arr.random();
    arr.print();
    arr.transpose();
    arr.print();
}

void findMin(){
    std::cout << "the minimal value of array" << std::endl;
    int shape[2] = {3, 3};
    NDArray<int> arr(2, shape);
    arr.random();
    int minimum = arr.min();
    std::cout << minimum;
    
}

void findMax(){
    std::cout << "the maximum value of array" << std::endl;
    int shape[2] = {3, 3};
    NDArray<int> arr(2, shape);
    arr.random();
    int maximum = arr.max();
    std::cout << maximum;
}

void findAverage(){
    std::cout << "the average value of array" << std::endl;
    int shape[2] = {3, 3};
    NDArray<int> arr(2, shape);
    arr.random();
    float average = arr.average();
    std::cout << average;
}