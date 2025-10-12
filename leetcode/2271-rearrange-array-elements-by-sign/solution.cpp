class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (int i:nums){
            if (i>=0){
                pos.push_back(i);
            }
            else{
                neg.push_back(i);
            }
        }
        vector<int> res;
        int posc=0;
        int negc=0;
        while(posc<pos.size() && negc<neg.size()){
            res.push_back(pos[posc++]);
            res.push_back(neg[negc++]);
        }
        return res;
    }
};
