class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        k=k%n;
        
        //Left operation for even indexed rows
        for (int i=0;i<mat.size();i+=2){
            vector<int> temp=mat[i];
            rotate(temp.begin(),temp.begin()+k,temp.end());
            if(temp!=mat[i]){
                return false;
            }
        }
        for (int i=1;i<mat.size();i+=2){
            vector<int> temp=mat[i];
            rotate(temp.begin(),prev(temp.end(),k),temp.end());
            if(temp!=mat[i]){
                return false;
            }
        }
        return true;
    }
};
