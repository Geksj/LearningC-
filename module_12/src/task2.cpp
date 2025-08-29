#include <iostream>
#include "task2.h"

void merge(const float* a, int lenA, const float* b, int lenB, float* c) {
    int i = 0;
    int j = 0;

    while (i < lenA && j < lenB) {
        if (a[i] < b[j]) {
            c[i + j] = b[j];
            j++;
        } else {
            c[i + j] = a[i];
            i++;
        }
    }

    while (i < lenA) {
        c[i + j] = a[i];
        i++;
    }

    while (j < lenB) {
        c[i + j] = b[j];
        j++;
    }
}

void mergeSort(float* a, int lenA) {
    if (lenA <= 1) return;

    int firstLen = lenA / 2;
    int secondLen = lenA - firstLen;
    mergeSort(a, firstLen);
    mergeSort(a + firstLen, secondLen);
    float* c = new float[lenA];
    merge(a, firstLen, a + firstLen, secondLen, c);
    memcpy(a, c, lenA * sizeof(float));
    delete[] c;
}

void task2() {
    float arr[15] = {1.2f, 2.3f, 1.11f, 3.4f, 5.5f, 5.4f, 5.3f, 5.1f, 1.5f, 1.25f, 5.41f, 5.31f, 5.11f, 1.51f, 1.251f };

    mergeSort(arr, 15);

    for(int i = 0; i < 15; i++) {
        std::cout << arr[i] << " ";
    }
}