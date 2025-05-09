#include <stdio.h>

// Function to calculate Fibonacci series
void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Function to calculate Factorial
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to find Minimum & Maximum in an array
void findMinMax(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    printf("Minimum Element: %d\n", min);
    printf("Maximum Element: %d\n", max);
}

// Main function with menu-driven approach
int main() {
    int choice, n;

    while (1) {
        printf("\n====== MENU ======\n");
        printf("1. Fibonacci Series\n");
        printf("2. Factorial\n");
        printf("3. Find Min & Max in Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of terms for Fibonacci: ");
                scanf("%d", &n);
                fibonacci(n);
                break;

            case 2:
                printf("Enter a number to find factorial: ");
                scanf("%d", &n);
                printf("Factorial of %d = %lld\n", n, factorial(n));
                break;

            case 3:
                printf("Enter number of elements in array: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                findMinMax(arr, n);
                break;

            case 4:
                printf("Exiting program. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
