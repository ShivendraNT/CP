#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minOverallFinish = INT_MAX;

        // Iterate through every possible pair of land and water rides
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                // Case 1: Land Ride First -> Water Ride Second
                int landFinish = landStartTime[i] + landDuration[i];
                int finalFinish1 = max(landFinish, waterStartTime[j]) + waterDuration[j];
                
                // Case 2: Water Ride First -> Land Ride Second
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int finalFinish2 = max(waterFinish, landStartTime[i]) + landDuration[i];
                
                // Track the absolute minimum finish time found so far
                minOverallFinish = min({minOverallFinish, finalFinish1, finalFinish2});
            }
        }

        return minOverallFinish;
    }
};
