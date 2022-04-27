public class cc {
    public static void main(String[] args) {
        String text = "A friend in need is a friend indeed";
        char[] newArray = new char[text.length()];
        newArray = text.toCharArray();
        int rotationInteger = 20;
        String output = "";
        int newIndex = 0;

        char[] lowercaseAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        char[] uppercaseAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        char[] charactersList = {' ', '?', ',', '\'', '"', '.', '/', '-', '_', '+', '=', ']', '[', '}', '{', ';', ':', '>', '<', '~', '`', '\\', '|', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
        char[] numbersList = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        
        for (int letter = 0; letter < newArray.length; letter++) {
            for (int i = 0; i < lowercaseAlphabet.length; i++) {
                if (newArray[letter] == lowercaseAlphabet[i]) {
                    newIndex = i + rotationInteger;
                    if (newIndex > 26) {
                        if (newIndex % 26 == 0) {
                            newIndex = 26;
                        }
                        else {
                            newIndex %= 26;
                        }
                    }
                    output += lowercaseAlphabet[newIndex];
                }
            }
            for (int j = 0; j < uppercaseAlphabet.length; j++) {
                if (newArray[letter] == uppercaseAlphabet[j]) {
                    newIndex = j + rotationInteger;
                    if (newIndex > 26) {
                        if (newIndex % 26 == 0) {
                            newIndex = 26;
                        }
                        else {
                            newIndex %= 26;
                        }
                    }
                    output += uppercaseAlphabet[newIndex];
                }
            }
            for (int num = 0; num < numbersList.length; num++) {
                if (newArray[letter] == numbersList[num]) {
                    output += numbersList[num];
                }
            }
            for (int value = 0; value < charactersList.length; value++) {
                if (newArray[letter] == charactersList[value]) {
                    output += charactersList[value];
                }
            }
        }

        System.out.println(output);
    }
}
