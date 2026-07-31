class Solution {
public:
    string largestEven(string s) {
        int n=s.size();
        int i=n-1;
        for(;i>=0;i--){
            if(s[i]=='2'){
                break;
            }
        }
        if(i==-1){
            return "";
        }
        return s.substr(0,i+1);
    }
};
