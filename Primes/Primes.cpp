//Gregory Ecklund
//April 2023

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string toString(int listOfPrimes [], int numOfIndexes) {
    string output = "[";
    for (int i = 0; i < numOfIndexes; i++) {
        output += to_string(listOfPrimes[i]);
        if (i != (numOfIndexes - 1)) {
            output += ", ";
        }
    }
    output += "]\n";
    return output;
}


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

    std::cout << toString(listOfPrimes, currentIndex) << std::endl;
    return 0;
}
