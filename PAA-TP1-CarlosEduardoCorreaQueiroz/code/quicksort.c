#include "sorts.h"

int partition(unsigned int arr[], int low, int high) {
    unsigned int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            unsigned int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    unsigned int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(unsigned int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
