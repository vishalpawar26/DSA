#include <iostream>
using namespace std;

inline int findMid(int s, int e) {
    return s + (e-s) / 2;
}

void merge(int *arr, int s, int e) {
    int mid = findMid(s, e);

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1]; 
    int *second = new int[len2];

    // Copy arrays
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge two sorted arrays
    int idx1 = 0;
    int idx2 = 0;
    mainArrayIndex = s;

    while (idx1 < len1 && idx2 < len2) {
        if (first[idx1] < second[idx2]) {
            arr[mainArrayIndex++] = first[idx1++];
        }
        else {
            arr[mainArrayIndex++] = second[idx2++];
        }
    }

    while (idx1 < len1) {
        arr[mainArrayIndex++] = first[idx1++];
    }

    while (idx2 < len2) {
        arr[mainArrayIndex++] = second[idx2++];
    }

    delete [] first;
    delete [] second;
}

void mergeSort(int *arr, int s, int e) {
    if (s >= e) {
        return;
    }
    
    int mid = findMid(s, e);

    // Left Part
    mergeSort(arr, s, mid);

    // Right Part
    mergeSort(arr, mid+1, e);

    // Merge both the parts
    merge(arr, s, e);
}

int main() {
    int n = 7;
    int arr[n] = {5,1,21,3,64,52,16};

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}