class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int numzero=0;
        int numone=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                numone++;
            }
            else if(s[i]=='0'){
                numzero++;
            }
        }
        vector<bool> ans;
        for(string curr:strs){
            int currones=0;
            int currzero=0;
            int currq=0;
            for(int i=0;i<n;i++){
                if(curr[i]=='1'){
                    currones++;
                }
                else if(curr[i]=='0'){
                        currzero++;
                }
                else{
                    currq++;
                }
            }
            if(currones>numone||currzero>numzero){
                ans.push_back(false);
                continue;
            }
            int ones=numone-currones;
            string target=curr;
            for(int i=n-1;i>=0;i--){
                if(target[i]=='?'){
                    if(ones>0){
                        target[i]='1';
                        ones--;
                    }
                    else{
                        target[i]=0;
                    }
                }
            }
            int sone=0;
            int tone=0;
            bool corr=true;
            for(int i=0;i<n;i++){
                if(s[i]=='1') sone++;
                if(target[i]=='1') tone++;
                if(tone>sone){
                    corr=false;
                    break;
                }
            }
            ans.push_back(corr);
        }
    return ans;
    }
};
