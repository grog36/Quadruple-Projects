#Gregory Ecklund
#September 2022

text = "You can make this say whatever you want." #Text to encrypt/decrypt
rotation_integer = 1 #Amount to rotate cipher by (positive or negative)

lowercase_alphabet = "abcdefghijklmnopqrstuvwxyz"
uppercase_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
remaining_characters = "1234567890 ?,\'\"./-_+=][}{;:><~`\\|!@#$%^&*()"

output = ""
new_index = 0
for letter in text:
    for i in range(len(lowercase_alphabet)):
        if letter == lowercase_alphabet[i]:
                new_index = i + rotation_integer
                if new_index > 25:
                    new_index %= 26
                output += lowercase_alphabet[new_index]
    for j in range(len(uppercase_alphabet)):
        if letter == uppercase_alphabet[j]:
            new_index = j + rotation_integer
            if new_index > 25:
                new_index %= 26
            output += uppercase_alphabet[new_index]
    for k in remaining_characters:
        if letter == k:
            output += letter

print(output)
