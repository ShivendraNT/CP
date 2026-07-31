class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
        int i=n-1;
        for(;i>=0;i--){
            if(s[i]!='a' && s[i]!='e' && s[i]!='o' && s[i]!='i' && s[i]!='u'){
                break;
            }
        }
        if(i==-1){
            return "";
        }
        return s.substr(0,i+1);
    }
};
