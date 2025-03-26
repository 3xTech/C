#include <stdio.h>

long long properFractions(long long n) {
    if (n == 1) {
        return 0;
    }

    long long result = n;  // Start with n
    long long p = 2;       // Smallest prime factor

    // Check for prime factors starting from 2
    while (p * p <= n) {
        if (n % p == 0) {
            // If p is a prime factor, divide n by p completely
            while (n % p == 0) {
                n /= p;
            }
            // Apply Euler's Totient formula: result *= (1 - 1/p)
            result -= result / p;
        }
        p++;
    }

    // If n is greater than 1, then it is a prime factor itself
    if (n > 1) {
        result -= result / n;
    }

    return result;
}


int main(){
	//doTest(1,  0);
	// doTest(2,  1);
	/*   doTest(5,  4);
    doTest(15,  8);
    doTest(25,  20);*/
	properFractions(15);
}