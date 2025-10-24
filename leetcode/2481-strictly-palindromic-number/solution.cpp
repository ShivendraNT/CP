class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int i=2;i<n-1;i++){
            int num=n;
            vector<int> base;
            while(num!=0){
                base.push_back(num%i);
                num=num/i;
            }
            vector<int> revbase=base;
            reverse(base.begin(),base.end());
            for (int j=0;j<base.size();j++){
                if (base[j]!=revbase[j]){
                    return false;
                }
            }
        }
        return true;
    }
};
