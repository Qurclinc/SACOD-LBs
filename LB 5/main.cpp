#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

std::vector<int> generateArray(int len) {
    std::vector<int> arr;
    int start = -200, end = 200;
    for (int i = 0; i < len; i++) {
        arr.push_back(rand() % (end - start + 1) + start);
    }
    return arr;
}

void print(std::vector<int> &arr) {
    for (auto i : arr) {
        printf("%d ", i);
    }
    printf("\n");
}

void hairbrushSort(std::vector<int> &arr) {
    double factor = 1.247;
    double gapFactor = arr.size() / factor;

    while (gapFactor > 1) {
        int gap = round(gapFactor);
        for (int i = 0, j = gap; j < arr.size(); i++, j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
        gapFactor /= factor;
    }
}

void stoogeSort(std::vector<int> &arr, int l = 0, int h = -1) {
    if (h == -1) {
        h = arr.size() - 1;
    }
    if (l >= h) {
        return;
    }
    if (arr[l] > arr[h]) {
        std::swap(arr[l], arr[h]);
    }

    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;
        stoogeSort(arr, l, h - t);
        stoogeSort(arr, l + t, h);
        stoogeSort(arr, l, h - t);
    }
}

int main() {
    srand(time(0));
    std::vector<int> arr = generateArray(10);
    print(arr);
    //hairbrushSort(arr);
    stoogeSort(arr);
    print(arr);
    return 0;
} 