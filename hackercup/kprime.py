

# Sieve
sieve = [1 for _ in range(10000001)]    # initially, assume all to be prime
prime_factors = [0 for _ in range(10000001)]

# starting point
prime = 2
multiple = 2
idx = 4

while prime < 10000001:
    prime_factors[prime] += 1
    while idx < 10000001:
        sieve[idx] = 0
        prime_factors[idx] += 1
        multiple += 1
        idx = multiple * prime
    prime += 1
    while(prime < 10000001 and sieve[prime] == 0):
        prime += 1
    multiple = 2
    idx = multiple * prime

cas = input()
for i in range(1, cas + 1):
    a, b, k = [int(x) for x in raw_input().split(" ")]
    no_primacity_k = 0
    for no in range(a, b + 1):
        if prime_factors[no] == k:
            no_primacity_k += 1
    print "Case #" + str(i) + ": " + str(no_primacity_k)
