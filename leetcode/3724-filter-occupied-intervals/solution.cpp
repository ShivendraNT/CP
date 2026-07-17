class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) {
            return {};
        }

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;
        for (const auto& interval : occupiedIntervals) {
            if (merged.empty()) {
                merged.push_back(interval);
            } else {
                int prevEnd = merged.back()[1];
                int currStart = interval[0];
                int currEnd = interval[1];
                if (currStart <= prevEnd + 1) {
                    merged.back()[1] = max(prevEnd, currEnd);
                } else {
                    merged.push_back(interval);
                }
            }
        }

        vector<vector<int>> result;
        for (const auto& interval : merged) {
            int start = interval[0];
            int end = interval[1];

            if (end < freeStart) {
                result.push_back({start, end});
            }
            else if (start > freeEnd) {
                result.push_back({start, end});
            }
            else {
                if (start < freeStart) {
                    result.push_back({start, freeStart - 1});
                }
                if (end > freeEnd) {
                    result.push_back({freeEnd + 1, end});
                }
            }
        }

        return result;
    }
};
