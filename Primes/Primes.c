//Gregory Ecklund
//April 2023

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int num = 10000; //Changeable upper-limit
    int currentIndex = 0;
    bool isPrime = true;
    int listOfPrimes[num];

    for (int i = num; i > 1; i--) {
        for (int j = 2; j < floor(sqrt(i) + 1); j++) {
            if (i % j == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {
            listOfPrimes[currentIndex] = i;
            currentIndex++;
        }
        else {
            isPrime = true;
        }
    }

    //Print primes
    printf("[");
    for (int i = 0; i < currentIndex; i++) {
        printf("%d", listOfPrimes[i]);
        if (i != (currentIndex - 1)) {
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}