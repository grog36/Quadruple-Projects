//Gregory Ecklund
//September 2022

#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "You can make this say whatever you want."; //Text to encrypt/decrypt
    int rotationInteger = 1; //Amount to rotate cipher by (positive or negative)

    string lowercaseAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string uppercaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string remainingCharacters = "1234567890 ?,\'\"./-_+=][}{;:><~`\\|!@#$%^&*()";
    
    string output = "";
    int newIndex = 0;
    for (int letterIndex = 0; letterIndex < text.length(); letterIndex++) {
        for (int i = 0; i < lowercaseAlphabet.length(); i++) {
            if (text[letterIndex] == lowercaseAlphabet[i]) {
                newIndex = i + rotationInteger;
                if (newIndex > 25) {
                    if (newIndex % 26 == 0) {
                        newIndex = 0;
                    }
                    else {
                        newIndex %= 26;
                    }
                }
                output += lowercaseAlphabet[newIndex];
            }
        }
        for (int j = 0; j < uppercaseAlphabet.length(); j++) {
            if (text[letterIndex] == uppercaseAlphabet[j]) {
                newIndex = j + rotationInteger;
                if (newIndex > 25) {
                    if (newIndex % 26 == 0) {
                        newIndex = 0;
                    }
                    else {
                        newIndex %= 26;
                    }
                }
                output += uppercaseAlphabet[newIndex];
            }
        }
        for (int k = 0; k < remainingCharacters.length(); k++) {
            if (text[letterIndex] == remainingCharacters[k]) {
                output += remainingCharacters[k];
            }
        }
    }

    std::cout << output << std::endl;

    return 0;
}