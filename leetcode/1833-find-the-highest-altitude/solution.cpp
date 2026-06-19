class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        long long alt=0;
        long long maxalt=0;
        for(int i:gain){
            alt+=i;
            maxalt=max(maxalt,alt);
        }
        return maxalt;
    }
};
