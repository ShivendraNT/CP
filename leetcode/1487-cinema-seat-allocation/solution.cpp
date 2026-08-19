class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << (col - 2));
            }
        }

        const int leftBlock  = 15;
        const int rightBlock = 240;
        const int midBlock   = 60;

        int ans = 0;

        for (auto const& [row, mask] : rowMask) {
            bool leftEmpty  = (mask & leftBlock) == 0;
            bool rightEmpty = (mask & rightBlock) == 0;
            bool midEmpty   = (mask & midBlock) == 0;

            if (leftEmpty && rightEmpty) {
                ans += 2;
            } else if (leftEmpty || rightEmpty || midEmpty) {
                ans += 1;
            }
        }

        // Add 2 groups for every row that had zero reservations in seats 2..9
        ans += 2 * (n - (int)rowMask.size());

        return ans;
    }
};
