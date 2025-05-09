#include <stdio.h>
#include <string.h>

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int max = arr[0];

    // Find the maximum value in arr[]
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int count[max + 1];
    memset(count, 0, sizeof(count));

    // Store count of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Modify count array to store actual positions
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];

    // Build the sorted array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy output to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements (non-negative only): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
