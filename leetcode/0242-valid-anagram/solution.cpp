class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int> mp;
        for (char i:s){
            if (mp[i]){
                mp[i]+=1;
            }
            else{
                mp[i]=1;
            }
        }
        for (char i:t){
            if (mp[i]){
                if (mp[i]>0){
                    mp[i]-=1;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            } 
        }
        return true;
    }
};
