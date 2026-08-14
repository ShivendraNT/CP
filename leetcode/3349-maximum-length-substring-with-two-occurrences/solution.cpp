class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mpp;
        int maxlen=0;
        int n=s.size();
        int i=0;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
    }
};
