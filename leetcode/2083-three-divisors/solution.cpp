class Solution {
public:
    bool isThree(int n) {
        int div=1;
        for (int i=2;i<=n;i++){
            if (div>3){
                return false;
            }
            if (n%i==0){
                div++;
            }
        }
        return div==3;
    }
};
