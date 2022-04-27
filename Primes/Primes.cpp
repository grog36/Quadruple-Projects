#include <iostream>
#include <string>
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
    int num = 100;
    int currentIndex = 0;
    bool test = true;
    int listOfPrimes [num];

    for (int i = num; i > 1; i--) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                test = false;
            }
        }
        if (test == true) {
            listOfPrimes[currentIndex] = i;
            currentIndex++;
        }
        test = true;
    }

    std::cout << toString(listOfPrimes, currentIndex);
}