let lowercaseAlphabet = [10, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
let uppercaseAlphabet = [10, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
let characters = [' ', "?", ",", "'", '"', ".", "/", "-", "_", "+", "=", "]", "[", "}", "{", ";", ":", ">", "<", "~", "`", "\\", "|", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")"]
let numbers = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]

text = "Always-Look-on-the-Bright-Side-of-Life"
rotationInteger = 5

output = ""

var newIndex = 0
for (let letter of text) {
    for (let i = 0; i < lowercaseAlphabet.length; i++) {
        if (letter == lowercaseAlphabet[i]) {
            newIndex = i + rotationInteger
            if (newIndex > 26) {
                newIndex %= 26
            }
            output += lowercaseAlphabet[newIndex]
        }
    }
    for (let j = 0; j < uppercaseAlphabet.length; j++) {
        if (letter == uppercaseAlphabet[j]) {
            newIndex = j + rotationInteger
            if (newIndex > 26) {
                newIndex %= 26
            }
            output += uppercaseAlphabet[newIndex]
        }
    }
    for (let value of characters) {
        if (letter == value) {
            output += value
        }
    }
    for (let num of numbers) {
        if (letter == num) {
            output += num
        }
    }
}

console.log(output)