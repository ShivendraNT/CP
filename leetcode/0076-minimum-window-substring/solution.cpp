class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int minlen=INT_MAX;
        int n=t.size();
        int start_idx=-1;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[t[i]]++;
        }
        int cnt=0;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>0){
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt==n){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    start_idx=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return (start_idx==-1)? "":s.substr(start_idx,minlen);
    }
};
