//Gregory Ecklund
//September 2022

let text = "You can make this say whatever you want."; //Text to encrypt/decrypt
let rotationInteger = 1; //Amount to rotate cipher by (positive or negative)

let lowercaseAlphabet = "abcdefghijklmnopqrstuvwxyz";
let uppercaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
let remainingCharacters = "1234567890 ?,\'\"./-_+=][}{;:><~`\\|!@#$%^&*()";

output = "";
let newIndex = 0;
for (let letter of text) {
    for (let i = 0; i < lowercaseAlphabet.length; i++) {
        if (letter === lowercaseAlphabet[i]) {
            newIndex = i + rotationInteger;
            if (newIndex > 25) {
                newIndex %= 26;
            }
            output += lowercaseAlphabet[newIndex];
        }
    }
    for (let j = 0; j < uppercaseAlphabet.length; j++) {
        if (letter === uppercaseAlphabet[j]) {
            newIndex = j + rotationInteger;
            if (newIndex > 25) {
                newIndex %= 26;
            }
            output += uppercaseAlphabet[newIndex];
        }
    }
    for (let k of remainingCharacters) {
        if (letter === k) {
            output += letter;
        }
    }
}

console.log(output);