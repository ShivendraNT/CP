class Solution {
public:
    string reverseWords(string s) {
        string result;

        for (int i=0;i<s.size();i++){
            if(s[i]==' '){
                continue;
            }
            string word;
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            if(result.empty()){
                result=word;
            }
            else{
            result=word+' '+result;
            }
        }
        return result;
    }
};
