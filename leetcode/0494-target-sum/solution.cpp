class Solution {
public:
int countPartitions(int n, int diff, vector<int>& arr) {
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }
    
    if (totalsum - diff < 0 || (totalsum + diff) % 2 != 0) return 0;
    int target = (totalsum + diff) / 2;
    vector<int> prev(target + 1, 0);
    prev[0]=1;
    if(arr[0] <= target) {
        prev[arr[0]] += 1; 
    }
    for(int i=1;i<n;i++){
        vector<int> curr(target+1,0);
        for(int j = 0; j <= target; j++) {
            int nottaken = prev[j];
            int taken = 0;
                
            if(arr[i] <= j) {
                taken = prev[j - arr[i]];
            }
            curr[j] = (nottaken + taken) ;
        }
        prev = curr;
    }
    return prev[target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),abs(target),nums);
    }
};
