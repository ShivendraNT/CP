class Solution {
private:
    void generate(int k,int n,vector<int> & current,vector<vector<int>> &result,int start){
        if(current.size()==k && n==0){
            result.push_back(current);
            return;
        }
        if(current.size()>k || n<0){
            return;
        }
        for(int i=start;i<=9;++i){
            current.push_back(i);
            generate(k,n-i,current,result,i+1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        generate(k, n, current, result,1);
        return result;
    }
};
