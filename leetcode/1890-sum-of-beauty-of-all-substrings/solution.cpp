class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for (int i=0;i<s.length();i++){
            unordered_map<int,int> freq;

            for (int j=i;j<s.length();j++){
                freq[s[j]]++;

                int maxi=INT_MIN;
                int mini=INT_MAX;

                for (auto it:freq){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                sum+=(maxi-mini);
            }
            
        }
        return sum;
    }
};
