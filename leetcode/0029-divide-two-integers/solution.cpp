class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == divisor) return 1;
        bool sign = (dividend < 0) == (divisor < 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            long long temp = d, count = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            n -= temp;
            ans += count;
        }

        return sign ? ans : -ans;
    }
};
