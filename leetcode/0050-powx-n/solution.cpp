class Solution {
public:
    double binaryPow(double x, long long n) {
        if (n == 0) return 1.0;
        if (n % 2 == 0) return binaryPow(x * x, n / 2);
        return x * binaryPow(x * x, n / 2);
    }

    double myPow(double x, int n) {
        long long N = n; 
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return binaryPow(x, N);
    }
};
