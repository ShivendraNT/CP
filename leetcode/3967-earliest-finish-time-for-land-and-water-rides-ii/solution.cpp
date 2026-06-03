#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int calculateSequenceTime(const vector<int>& start1, const vector<int>& dur1,
                              const vector<int>& start2, const vector<int>& dur2) {
        
        // Step 1: Find the absolute earliest time we can finish ANY ride of the first type
        int minFirstRideFinish = INT_MAX;
        for (size_t i = 0; i < start1.size(); ++i) {
            minFirstRideFinish = min(minFirstRideFinish, start1[i] + dur1[i]);
        }

        // Step 2: Find the best second ride to pair with that earliest finish time
        int minTotalFinish = INT_MAX;
        for (size_t j = 0; j < start2.size(); ++j) {
            int currentFinish = max(minFirstRideFinish, start2[j]) + dur2[j];
            minTotalFinish = min(minTotalFinish, currentFinish);
        }

        return minTotalFinish;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        // Direction A: Land first, then Water
        int landFirst = calculateSequenceTime(landStartTime, landDuration, waterStartTime, waterDuration);
        
        // Direction B: Water first, then Land
        int waterFirst = calculateSequenceTime(waterStartTime, waterDuration, landStartTime, landDuration);
        
        // The optimal result is the minimum of both sequences
        return min(landFirst, waterFirst);
    }
};
