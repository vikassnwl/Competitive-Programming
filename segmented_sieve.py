# implementation of segmented sieve

MAX = 32000
def sieve():
    """
    creating sieve of size 32001
    """
    isPrime = [1 for _ in range(MAX+1)]
    print(len(isPrime))
    for i in range(2, int(MAX**.5)+1):
        for j in range(i*i, MAX+1, i):
            if isPrime[j] == 1:
                isPrime[j] = 0
    primes = []
    for i in range(2, MAX+1):
        if isPrime[i] == 1:
            primes.append(i)
    print(len(primes))
    return primes



t = int(input())
for _ in range(t):
    primes = sieve()
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
