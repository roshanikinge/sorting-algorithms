#include <stdio.h>
#include <stdlib.h>

// Function to perform Insertion Sort
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    float bucket[n][n];
    int count[n];

    for (int i = 0; i < n; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++) {
        int idx = arr[i] * n;
        bucket[idx][count[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++)
        insertionSort(bucket[i], count[i]);

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < count[i]; j++)
            arr[index++] = bucket[i][j];
}

// Main function
int main() {
    float arr[] = {0.23, 0.14, 0.91, 0.42, 0.34};
    int n = 5;
    
    bucketSort(arr, n);
    
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
}
