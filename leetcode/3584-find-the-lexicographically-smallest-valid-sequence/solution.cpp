class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> sub(n+1,0);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            sub[i]=sub[i+1];
            if(j>=0 && word1[i]==word2[j]){
                sub[i]++;
                j--;
            }
        }
        vector<int> ans;
        int jj=0;
        bool used=false;
        for(int i=0;i<n && jj<m;i++){
            if(word1[i]==word2[jj]){
                ans.push_back(i);
                jj++;
            }
            else{
                if(!used && sub[i+1]>=m-(jj+1)){
                    used=true;
                    ans.push_back(i);
                    jj++;
                }
            }
        }
        if(jj==m){
            return ans;
        }
        return {};
    }
};
