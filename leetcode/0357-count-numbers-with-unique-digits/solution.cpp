class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n > 10) n = 10; // Cannot have unique digits beyond 10 slots

        int totalCount = 10; // Base case for n=1
        int currentLengthOptions = 9; // Choices for the first digit (1-9)
        int availableNumbers = 9; // Remaining choices for subsequent positions
        
        for (int i = 2; i <= n; i++) {
            currentLengthOptions *= availableNumbers;
            totalCount += currentLengthOptions;
            availableNumbers--;
        }
        
        return totalCount;
    }
};
