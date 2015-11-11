
#include <iostream>
#include <cmath>
#include <bitset>
#include <list>


/* The maximum value of the input number */
static const long long upper_limit = 10e12;

/* The prime list, defined later, maintains a list of
 * all the primes upto `primes_till` */
static const long long primes_till = sqrt(upper_limit);


int main() {

    std::list<long long> primelist;
    std::bitset<primes_till> sieve;

    for (long long num = 2; num < sqrt(primes_till); num++)
        for (long long multiple = 2 * num; multiple < primes_till; multiple += num)
            sieve.set(multiple);

    // Generate list
    for (long long num = 2; num < primes_till; num++)
        if (!sieve.test (num))  primelist.push_back (num);

    long long t, num;
    
    std::cin >> t;

    while (t--) {
        std::cin >> num; 
        
        /* stores just the exponents of the prime divisors of num */
        std::list<int> exponents;

        for (auto prime : primelist) {
            if (num <= 1 or prime * prime > num)    break;
            int times = 0;
            for (; num % prime == 0; times++, num /= prime);
            if(times)   exponents.push_back(times); 
        }
        /* If at the end of the above loop, number > 1, then there exists some 
         * prime factor > sqrt(num); Hence, push back 1;
         */
        if(num > 1)   exponents.push_back(1);

        /* if num = a^p * b^q * c^r, then tau(n) = (p+1)(q+1)(r+1) */
        long long product = 1;
        for(int exp : exponents)    product *= exp + 1;
        
        std::cout << product << std::endl;
    }

}
