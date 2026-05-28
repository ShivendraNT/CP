class Solution {
public:
    void generate(int pos,string combos[],string s,string digits,vector<string>&ans){
        if(pos==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit=digits[pos]-'0';

        for(int i=0;i<combos[digit].size();i++){
            generate(pos+1,combos,s+combos[digit][i],digits,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combos[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        generate(0,combos,"",digits,ans);
        return ans;
    }
};
