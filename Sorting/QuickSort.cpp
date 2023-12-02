#include <iostream>
using namespace std;

int partition(int *arr, int s, int e) {
    int pivot = arr[s];

    // Find element that are smaller than the pivot
    int cnt = 0;
    for (int i = s+1; i <= e; i++) {
        if (pivot >= arr[i])
            cnt++;
    }

    int pivotIndex = s + cnt;

    // Swap the pivot with a element such that the pivot get its appropriet position
    swap(arr[s], arr[pivotIndex]);

    // Put all the smaller element on the left side and 
    // all the bigger elements on the right of the pivot
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
            i++;
        }
        
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {
    // Base case
    if (s >= e) 
        return;
    
    // Partition
    int p = partition(arr, s, e);

    // Sort left part
    quickSort(arr, s, p-1);

    // Sort right part
    quickSort(arr, p+1, e);    
}

int main() {
    int n = 7;
    int arr[n] = {5, 9, 1, 6, 4, 2, 6};

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;

    return 0;
}