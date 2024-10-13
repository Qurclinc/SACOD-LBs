#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Sorts.h"

std::vector<int> generateArray(int n);
void print(std::vector<int> &arr);

int main() {
    srand(time(0));
    const int N = 10;
    std::vector<int> arr = generateArray(N);
    print(arr);
    // ShakerSort(arr);
    QuickSort(arr, 0, N - 1);
    print(arr);
    return 0;
}

std::vector<int> generateArray(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

void print(std::vector<int> &arr) {
    for (auto i: arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}