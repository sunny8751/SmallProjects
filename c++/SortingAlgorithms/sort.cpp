#include <iostream>
#include <utility>
#include <vector>

void printArray(int arr[], int length) {
    //print
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}
    
void selectionSort(int arr[], int length) {
    std::cout << "Selection sort:\n";
    for (int iteration = 0; iteration < length; ++iteration) {
        int min(arr[iteration]);
        int minIndex(iteration);
        for (int i = iteration + 1; i < length; ++i) {
            if (arr[i] < min) {
                min = arr[i];
                minIndex = i;
            }
        }
        std::swap(arr[iteration], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int length) {
    std::cout << "Bubble sort:\n";
    for (int iteration = 0; iteration < length; ++iteration) {
        int numSwaps = 0;
        for (int i = 0; i < length - iteration - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                ++numSwaps;
            }
        }
        if (numSwaps == 0) {
            std::cout << "Sort terminated on " << iteration + 1 << " iteration.\n";
            return;
        }
    }
}

void insertionSort(int arr[], int length) {
    std::cout << "Insertion sort:\n";
    for (int iteration = 1; iteration < length; ++iteration) {
        int i = iteration - 1;
        while (i >= 0 && arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
            --i;
        }
    }
}

std::vector<int> quickSort1Helper(std::vector<int> arr) {
    if (arr.size() <= 1) return arr;
    int pivot = arr[0];
    std::vector<int> lessList, greaterList;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < pivot) {
            lessList.push_back(arr[i]);
        } else {
            greaterList.push_back(arr[i]);
        }
    }
    lessList = quickSort1Helper(lessList);
    greaterList = quickSort1Helper(greaterList);
    std::vector<int> list;
    list.reserve(lessList.size() + 1 + greaterList.size());
    list.insert(list.end(), lessList.begin(), lessList.end());
    list.push_back(pivot);
    list.insert(list.end(), greaterList.begin(), greaterList.end());
    lessList.clear();
    greaterList.clear();
    return list;
}

void quickSort1(int arr[], int length) {
    std::cout << "Quick sort using external memory:\n";
    std::vector<int> v(arr, arr + length);
    arr = quickSort1Helper(v).data();
    printArray(arr, length);
}

void quickSort2(int arr[], int length) {
    std::cout << "Quick sort using internal memory:\n";
}

void quickSort3(int arr[], int length) {
    std::cout << "Quick sort using internal memory with two pivots:\n";
}

int main() {
    int length1 = 5;
    int arr1[] = {30, 50, 20, 10, 40};

    selectionSort(arr1, length1);
    printArray(arr1, length1);

    int length2 = 9;
    int arr2[] = {6, 3, 2, 9, 7, 1, 5, 4, 8};

    bubbleSort(arr2, length2);
    printArray(arr2, length2);

    int length3 = 8;
    int arr3[] = {4, 6, 5, 2, 9, 3, 1, 7};

    insertionSort(arr3, length3);
    printArray(arr3, length3);

    int length4 = 7;
    int arr4[] = {6, 8, 3, 9, 1, 6, 3};

    quickSort1(arr4, length4);

    return 0;
}
