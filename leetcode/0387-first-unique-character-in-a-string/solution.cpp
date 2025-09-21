class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> count;
        for (char ch:s){
            count[ch]+=1;
        }
        vector<int> ones;
        for (const auto &p:count){
            if (p.second==1){
                ones.push_back(s.find(p.first));
            }
        }
        if (ones.size()==0){
            return -1;
        }
    auto it= min_element(ones.begin(),ones.end());
    int ans=*it;
    return ans;
    }
};
