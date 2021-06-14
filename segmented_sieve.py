# implementation of segmented sieve
 
primes = [2]
for i in range(3, 32000, 2):
    isPrime = True
    cap = int(i**.5)
    for j in primes:
        if j > cap:
            break
        if i%j == 0:
            isPrime = False
            break
    if isPrime:
        primes.append(i)
 
t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    if l < 2:
        l = 2
    segmented_sieve = [1]*(r-l+1)
    i = 0
    while primes[i]**2 <= r:
        currPrime = primes[i]
        base = l//currPrime*currPrime
        if base < l:
            base += currPrime
        for j in range(base, r+1, currPrime):
            segmented_sieve[j-l] = 0
        if base == currPrime:
            segmented_sieve[base-l] = 1
        i += 1
 
    for i in range(r-l+1):
        if segmented_sieve[i]:
            print(i+l)
    print()
