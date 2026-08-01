class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0=0;
        int cnt1=0;
        int ans=0;
        for(char c:s){
            if(c=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
            if(abs(cnt0-cnt1)<2){
                ans++;
            }
        }
        return ans;
    }
};
