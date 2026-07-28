class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        string ans="";
        int oddind=-1;
        for(int i=0;i<26;i++){
            if(freq[i]%2!=0){
                oddind=i;
            }
            ans += string(freq[i] / 2, i + 'a');
        }
        string res=ans;
        if(oddind!=-1){
            res += (oddind + 'a');
        }
        
        reverse(ans.begin(),ans.end());
        res+=ans;
        return res;
    }
};
