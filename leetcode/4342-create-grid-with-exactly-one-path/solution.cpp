class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string first="";
        string second="";
        for(int i=0;i<n;i++){
            first+='.';
            second+='#';
        }
        second[n-1]='.';
        ans.push_back(first);
        for(int i=1;i<m;i++){
            ans.push_back(second);
        }
        return ans;
    }
};
