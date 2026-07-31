class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;
        for(int b=16;b>=0;b--){
            int mask=ans|((1<<b) - 1);

            bool cankeepzero=true;
            for(auto & row:grid){
                bool found=false;
                for(int x:row){
                    if((x|mask)==mask) {
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cankeepzero=false;
                    break;
                }
            }
            if(!cankeepzero){
                ans|=(1<<b);
            }
        }
        return ans;
    }
};
