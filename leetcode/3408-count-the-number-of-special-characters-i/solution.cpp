class Solution {
public:
    int numberOfSpecialChars(string word) {
        sort(word.begin(),word.end());
        int capstart=0;
        for(;capstart<word.size();capstart++){
            if(word[capstart]>='A' && word[capstart]<='Z'){
                continue;
            }
            else{
                break;
            }
        }
        int low=0;
        int ans=0;
        while(capstart<word.size()&&low!=capstart){
            if(word[low]+32 == word[capstart]){
                ans++;
                while(word[low]==word[low+1]) low++;
                while(word[capstart]==word[capstart+1]) capstart++;
                low++;
                capstart++;
            }
            else if(word[low]+32>word[capstart]){
                while(word[capstart]==word[capstart+1]) capstart++;
                capstart++;
            }
            else{
                while(word[low]==word[low+1]) low++;
                low++;
            }
        }
        return ans;
    }
};
