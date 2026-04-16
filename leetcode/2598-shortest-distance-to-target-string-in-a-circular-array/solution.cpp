class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mini = n;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                mini = min({mini, dist, n - dist});
            }
        }

        return (mini == n) ? -1 : mini;
    }
};
