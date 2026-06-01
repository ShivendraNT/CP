class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int i=cost.size()-1;
        int sum=0;
        while(i>1){
            //add leftmost
            sum+=cost[i--];

            // add second to left;
            sum+=cost[i--];

            // skip one for free;
            i--;
        }
        if(i!=-1){
            while(i>=0){
                sum+=cost[i--];
            }
        }
        return sum;
    }
};
