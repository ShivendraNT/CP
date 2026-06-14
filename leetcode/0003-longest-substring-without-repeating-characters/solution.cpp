class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> chrmap;
        int left=0;
        int maxl=0;
        for(int i=0;i<s.size();i++){
            if(chrmap.find(s[i])!=chrmap.end() && chrmap[s[i]]>=left){
                left=chrmap[s[i]]+1;
            }
            chrmap[s[i]]=i;
            maxl=max(maxl,i-left+1);
        }
        return maxl;
    }
};
