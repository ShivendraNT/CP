class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> values;
        if (s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char> mapping;
        for (int i=0;i<s.size();i++){
            auto it=mapping.find(s[i]);
            if(it != mapping.end()){
                if(it->second!=t[i]){
                    return false;
                }
            }
            else{
                mapping.insert({s[i],t[i]});
                if(find(values.begin(),values.end(),t[i])!=values.end()){
                    return false;
                }
                values.push_back(t[i]);
                
            }
        }
        return true;
    }
};
