
#include <bits/stdc++.h>

int main() {

    const long long primes_till = 23000000000;
    
    std::bitset<primes_till> sieve;

    for (long long num = 3; num < sqrt(primes_till); num += 2)
        for (long long multiple = 2 * num; multiple < primes_till; multiple += num)
            sieve.set(multiple);

        

    long long n;
    std::cin >> n;

    if (n == 1) std::cout << 2;
    n -= 1;

    for (long long num = 3; num < primes_till; num += 2) {
        if(!sieve.test(num))
            n--;
        if(!n) {
            std::cout << num << std::endl;
            break;
        }
    } 

}
