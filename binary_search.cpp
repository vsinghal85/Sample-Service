#include <iostream>
#include <vector>
#include <algorithm>

// Iterative Binary Search
int iterativeBinarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // Target not found
    return -1;
}

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, search in right half
        if (arr[mid] < target) {
            return recursiveBinarySearch(arr, target, mid + 1, right);
        }
        // If target is smaller, search in left half
        else {
            return recursiveBinarySearch(arr, target, left, mid - 1);
        }
    }

    // Target not found
    return -1;
}

int main() {
    std::vector<int> sortedArray = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target1 = 23;
    int target2 = 10;
    int target3 = 2;
    int target4 = 91;

    std::cout << "Original Array: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Iterative Binary Search Examples
    std::cout << "\n--- Iterative Binary Search ---" << std::endl;
    int index1_iterative = iterativeBinarySearch(sortedArray, target1);
    if (index1_iterative != -1) {
        std::cout << "Target " << target1 << " found at index: " << index1_iterative << std::endl;
    } else {
        std::cout << "Target " << target1 << " not found in the array." << std::endl;
    }

    int index2_iterative = iterativeBinarySearch(sortedArray, target2);
    if (index2_iterative != -1) {
        std::cout << "Target " << target2 << " found at index: " << index2_iterative << std::endl;
    } else {
        std::cout << "Target " << target2 << " not found in the array." << std::endl;
    }

    // Recursive Binary Search Examples
    std::cout << "\n--- Recursive Binary Search ---" << std::endl;
    int index1_recursive = recursiveBinarySearch(sortedArray, target3, 0, sortedArray.size() - 1);
    if (index1_recursive != -1) {
        std::cout << "Target " << target3 << " found at index: " << index1_recursive << std::endl;
    } else {
        std::cout << "Target " << target3 << " not found in the array." << std::endl;
    }

    int index2_recursive = recursiveBinarySearch(sortedArray, target4, 0, sortedArray.size() - 1);
    if (index2_recursive != -1) {
        std::cout << "Target " << target4 << " found at index: " << index2_recursive << std::endl;
    } else {
        std::cout << "Target " << target4 << " not found in the array." << std::endl;
    }

    return 0;
}
