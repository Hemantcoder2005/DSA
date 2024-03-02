# Bubble Sort Algorithm

This repository contains a simple implementation of the Bubble Sort algorithm in C++.

## Overview

Bubble sort is a straightforward sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items, and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted. Bubble sort is not efficient for large datasets, as it has a worst-case and average-case time complexity of O(n^2). However, it is easy to understand and implement, making it suitable for educational purposes or for sorting small lists.

## Implementation

The Bubble Sort algorithm is implemented in C++ in the `BubbleSort.cpp` file. The `BubbleSort` function takes an integer array and its size as input and sorts the array in ascending order using the Bubble Sort algorithm.

## Usage

To use the Bubble Sort algorithm, include the `BubbleSort.cpp` file in your C++ project and call the `BubbleSort` function, passing the integer array to be sorted and its size as arguments.

Example usage:

```cpp
#include <iostream>
#include "BubbleSort.cpp"

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    BubbleSort(arr, size);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
