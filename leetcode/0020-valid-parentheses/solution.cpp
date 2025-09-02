class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        unordered_map<char,char> mp = {{')','('},{'}','{'},{']','['}};
        for (char i : s){
            if (mp.count(i)){
                if (!stck.empty() && stck.top()==mp[i]){
                    stck.pop();
                }
                else{
                    return false;
                }
            }else {
                stck.push(i);
            }
        
            }
            return stck.empty();
        }
    };

