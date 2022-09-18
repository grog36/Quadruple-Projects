//Gregory Ecklund
//September 2022

import java.lang.Math;
public class Primes {
	public static void main(String[] args) {
		int limit = 10000;
		boolean isPrime = true;
		String output = "[";

		for (int i = limit; i >= 2; i--) {
			for (int j = 2; j < Math.floor(Math.sqrt(i)+1); j++) {
				if (i % j == 0) {
					isPrime = false;
				}
			}
			if (isPrime) {
				if (output == "[") {
					output += i;
				}
				else {
					output += ", " + i;
				}
			}
			else {
				isPrime = true;
			}
		}
		output += "]";
		System.out.println(output);
	}
}
