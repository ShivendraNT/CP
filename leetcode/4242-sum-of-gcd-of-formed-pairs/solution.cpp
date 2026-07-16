class Solution {
public:

    long long gcdSum(vector<int>& nums) {
        long long mx=0;
        vector<long long> pairs;
        for(int i:nums){
            if(i>mx){
                mx=i;
            }
            pairs.push_back(gcd(mx,i));
        }
        sort(pairs.begin(),pairs.end());
        long long right=pairs.size()-1;
        long long left=0;
        long long sum=0;
        while(left<right){
            sum+=gcd(pairs[left++],pairs[right--]);
        }
        return sum;
    }
};
