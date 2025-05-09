#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n < 2)
        return 0;  // Numbers less than 2 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;  // If divisible by any number other than 1 and itself, not prime
    }
    return 1;
}

// Main function
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d is a Prime Number.\n", num);
    else
        printf("%d is Not a Prime Number.\n", num);

    return 0;
}
