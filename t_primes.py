"""
It can be shown that only squares of prime numbers are T-primes, and that there are not too many of them — as many as there are prime numbers not greater than sqrt(10**12) = 10**6. Precompute these numbers (using, for example, the sieve of Eratosthenes) and store them in an array or an std::set, then we can answer each query by simply checking whether the number in question is amongst the precomputed numbers.
"""

# taking input from user
n = int(input())
arr = list(map(int, input().split()))
 
# creating sieve
sieve = [1 for _ in range(10**6+1)]
 
for i in range(2, 10**3+1):
    for j in range(i*i, 10**6+1, i):
        if sieve[j] != 0:
            sieve[j] = 0
 
# using sieve
for num in arr:
    if num == 1:
        print('NO')
    else:
        sqrt_num = num**.5
        if int(sqrt_num) == sqrt_num:
            if sieve[int(sqrt_num)] == 1:
                print('YES')
            else:
                print('NO')
        else:
            print('NO')
