#Gregory Ecklund
#September 2022

import math as Math

max_num = 10000
isPrime = True

list_of_primes = []

for i in range(max_num, 1, -1):
    for j in range(2, Math.floor(Math.sqrt(i)+1), 1):
        if (i % j == 0):
            isPrime = False
    if (isPrime):
        list_of_primes.append(i)
    else:
        isPrime = True

print(list_of_primes)
