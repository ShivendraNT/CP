class Solution {
public:
    bool canMake(const vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int count = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0; 
                }
            } else {
                count = 0; 
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, mid, m, k)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return ans;
    }
};
