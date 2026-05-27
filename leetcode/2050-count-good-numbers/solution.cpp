class Solution {
public:
    long long MOD = 1e9 + 7;

    // Custom binary exponentiation that handles modulo to prevent overflow
    long long power(long long base, long long exp) {
        long long res = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) { // If exp is odd
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD; // Square the base
            exp /= 2;                  // Halve the exponent
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long oddPositions = n / 2;
        long long evenPositions = n - oddPositions; // Simpler way to handle n/2 + 1 for odd n

        // Calculate (5^evenPositions) % MOD and (4^oddPositions) % MOD safely
        long long five = power(5, evenPositions);
        long long four = power(4, oddPositions);

        return (five * four) % MOD;
    }
};
