public class Primes {
    public static void main(String[] args) {
        int num = 100;
        boolean test = true;
        String output = "[";  

        for (int i=num; i>=2; i--) {
            for (int t=2; t<i; t++) {
                if (i%t==0) {
                    test = false;
                }
            }
            if (test==true) {
                if (output == "[") {
                    output += i;
                }
                else {
                    output += ", ";
                    output += i;
                }
            }
            test = true;
        }

        output += "]";
        System.out.println(output);
    }
}