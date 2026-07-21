class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int temp = n;
        int r = 0;
        while (temp > 0) {
            r = r * 10 + (temp % 10);
            temp /= 10;
        }

        int L = min(n, r);
        int R = max(n, r);

        if (R < 2) return 0;

        vector<bool> isPrime(R + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= R; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= R; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int primeSum = 0;
        for (int i = L; i <= R; i++) {
            if (isPrime[i]) {
                primeSum += i;
            }
        }

        return primeSum;
    }
};
