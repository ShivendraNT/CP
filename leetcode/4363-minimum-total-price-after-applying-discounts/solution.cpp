class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int j=discounts.size()-1;
        double ans=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(j>=0){
                ans+=((double)prices[i]*(double)(100-discounts[j]))/100;
                j--;
            }
            else{
                ans+=prices[i];
            }
        }
        return ans;
    }
};
