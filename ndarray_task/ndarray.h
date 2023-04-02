#ifndef NDARRAY_NDARRAY_H
#define NDARRAY_NDARRAY_H


#include <iostream>
#include <cstdlib>
#include <ctime>


template <typename T>
class NDArray {
private:
    int dim;
    T *arr;
    int *shape;

public:
    //Default Constructor
    NDArray(int d, int s[]) {
        dim = d;
        shape = new int[dim];
        for (int i = 0; i < dim; i++) {
            shape[i] = s[i];
        }
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        arr = new T[size];
    }

    NDArray(const NDArray &x) {
        dim = x.dim;
        shape = new int[dim];
        for (int i = 0; i < dim; i++) {
            shape[i] = x.shape[i];
        }
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = x.arr[i];
        }
    }
    // Creating an array filled with zeros
    void zeros() {
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = static_cast<T>(0);
        }
    }

    // Creating an array filled with ones
    void ones() {
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = static_cast<T>(1);
        }
    }

    // Creating an array filled with randoms
    void random() {
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        std::srand(std::time(NULL));
        for (int i = 0; i < size; i++) {
            arr[i] = static_cast<T>(std::rand()) / static_cast<T>(1);
        }
    }

    // array output function
    void print() {
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }

    // the element - by - element addition operator
    NDArray<T> operator+(NDArray<T> const &obj) {
        NDArray<T> result(dim, shape);
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + obj.arr[i];
        }
        return result;
    }

    // the element - by - element subtraction operator
    NDArray<T> operator-(NDArray<T> const &obj) {
        NDArray<T> result(dim, shape);
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] - obj.arr[i];
        }
        return result;
    }

    // the element - by - element multiply operator
    NDArray<T> operator*(NDArray<T> const &obj) {
        NDArray<T> result(dim, shape);
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] * obj.arr[i];
        }
        return result;
    }

    // the element - by - element division operator
    NDArray<T> operator/(NDArray<T> const &obj) {
        NDArray<T> result(dim, shape);
        int size = 1;
        for (int i = 0; i < dim; i++) {
            size *= shape[i];
        }
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] / obj.arr[i];
        }
        return result;
    }

    // matrix multiplication method
    NDArray<T> dot(NDArray<T> &x) {
    if (dim != 2 || x.dim != 2 || shape[1] != x.shape[0]) {
        throw std::invalid_argument("Invalid shapes for matrix multiplication");
    }
    int new_shape[2] = {shape[0], x.shape[1]};
    NDArray<T> result(2, new_shape);
    for (int i = 0; i < shape[0]; i++) {
        for (int j = 0; j < x.shape[1]; j++) {
            T sum = static_cast<T>(0);
            for (int k = 0; k < shape[1]; k++) {
                sum += arr[i * shape[1] + k] * x.arr[k * x.shape[1] + j];
            }
            result.arr[i * x.shape[1] + j] = sum;
        }
    }
    return result;
}

    // matrix transposition method
    NDArray<T> transpose() {
    if (dim != 2) {
        throw std::invalid_argument("Invalid shape for transpose");
    }
    int new_shape[2] = {shape[1], shape[0]};
    NDArray<T> result(2, new_shape);
    for (int i = 0; i < shape[0]; i++) {
        for (int j = 0; j < shape[1]; j++) {
            result.arr[j * shape[0] + i] = arr[i * shape[1] + j];
        }
    }
    return result;
}
    // finding the minimum value
    T min(int axis = -1) {
    if (axis < -1 || axis >= dim) {
        throw std::invalid_argument("Invalid axis for reduction");
    }
    int size = 1;
    for (int i = 0; i < dim; i++) {
        if (i != axis && shape[i] != 1) {
            throw std::invalid_argument("Invalid shape for reduction");
        }
        size *= shape[i];
    }
    T result = arr[0];
    for (int i = 0; i < size; i++) {
        if (i % shape[axis] == 0) {
            T temp = arr[i];
            for (int j = 1; j < shape[axis]; j++) {
                temp = std::min(temp, arr[i + j]);
            }
            result = i == 0 ? temp : std::min(result, temp);
        }
    }
    return result;
}

    // finding the maximum value
T max(int axis = -1) {
    if (axis < -1 || axis >= dim) {
        throw std::invalid_argument("Invalid axis for reduction");
    }
    int size = 1;
    for (int i = 0; i < dim; i++) {
        if (i != axis && shape[i] != 1) {
            throw std::invalid_argument("Invalid shape for reduction");
        }
        size *= shape[i];
    }
    T result = arr[0];
    for (int i = 0; i < size; i++) {
        if (i % shape[axis] == 0) {
            T temp = arr[i];
            for (int j = 1; j < shape[axis]; j++) {
                temp = std::max(temp, arr[i + j]);
            }
            result = i == 0 ? temp : std::max(result, temp);
        }
    }
    return result;
}
//finding the average value
T average(int axis = -1) {
    if (axis < -1 || axis >= dim) {
        throw std::invalid_argument("Invalid axis for reduction");
    }
    int size = 1;
    for (int i = 0; i < dim; i++) {
        if (i != axis && shape[i] != 1) {
            throw std::invalid_argument("Invalid shape for reduction");
        }
        size *= shape[i];
    }
    T result = static_cast<T>(0);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (i % shape[axis] == 0) {
            T temp = static_cast<T>(0);
            for (int j = 0; j < shape[axis]; j++) {
                temp += arr[i + j];
            }
            temp /= static_cast<T>(shape[axis]);
            result += temp;
            count++;
        }
    }
    return result / static_cast<T>(count);
}

    ~NDArray() {
        delete[] shape;
        delete[] arr;
    }
};


#endif