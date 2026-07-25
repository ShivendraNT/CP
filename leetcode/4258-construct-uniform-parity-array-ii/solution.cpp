class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long minodd=LLONG_MAX,mineven=LLONG_MAX;
        int oddcnt=0;
        int evencnt=0;
        for(int x:nums1){
            if(x&1){
                oddcnt++;
                minodd=min(minodd,(long long)x);
            }
            else{
                evencnt++;
                mineven=min(mineven,(long long)x);
            }
        }
        bool alleven=(oddcnt==0);
        bool allodd=(evencnt==0) || (oddcnt>=1 && minodd<mineven);
        return alleven||allodd;
    }
};
