class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        int ans=0;
        int cnt=0;
        int mul=1;
        for(int i=25;i>=0;i--){
            if(freq[i]==0){
                break;
            }
            cnt++;
            if(cnt>8){
                cnt=1;
                mul++;
            }
            ans+=freq[i]*mul;
        }
        return ans;
    }
};
