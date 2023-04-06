//Gregory Ecklund
//April 2023

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num = 10000; //Changeable upper-limit
    int currentIndex = 0;
    bool isPrime = true;
    int listOfPrimes [num];

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
    std::cout << "[";
    for (int i = 0; i < currentIndex; i++) {
        std::cout << listOfPrimes[i];
        if (i != (currentIndex - 1)) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
    return 0;
}