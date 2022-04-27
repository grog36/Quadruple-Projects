lowercase_alphabet = [0, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
uppercase_alphabet = [0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
characters = [" ", "?", ",", "'", '"', ".", "/", "-", "_", "+", "=", "]", "[", "}", "{", ";", ":", ">", "<", "~", "`", "\\", "|", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")"]
numbers = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]

text = "Always-Look-on-the-Bright-Side-of-Life"
rotation_integer = 5

output = ""

new_index = 0
for letter in text:
    for i in range(len(lowercase_alphabet)):
        if letter == lowercase_alphabet[i]:
                new_index = i + rotation_integer
                if new_index > 26:
                    if new_index % 26 == 0:
                        new_index = 26
                    else:
                        new_index = new_index % 26
                output += lowercase_alphabet[new_index]
    for j in range(len(uppercase_alphabet)):
        if letter == uppercase_alphabet[j]:
            new_index = j + rotation_integer
            if new_index > 26:
                if new_index % 26 == 0:
                    new_index = 26
                else:
                    new_index = new_index % 26
            output += uppercase_alphabet[new_index]
    for k in characters:
        if letter == k:
            output += k
    for l in numbers:
        if letter == l:
            output += l

print(output)
