num = 100
test = True

list_of_primes = []

for i in range(num, 1, -1):
    for j in range(2, i, 1):
        if (i % j == 0):
            test = False
    if (test == True):
        list_of_primes.append(i)
    test = True

print(list_of_primes)