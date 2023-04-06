#Gregory Ecklund
#September 2022

import math

max_num = 10000 #Changeable upper-limit
isPrime = True

list_of_primes = []

for i in range(max_num, 1, -1):
    for j in range(2, math.floor(math.sqrt(i)+1), 1):
        if (i % j == 0):
            isPrime = False
    if (isPrime):
        list_of_primes.append(i)
    else:
        isPrime = True

print(list_of_primes)