class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0;
        int maxsum=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        maxsum=sum;
        l=k-1;
        int r=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            sum-=cardPoints[l--];
            sum+=cardPoints[r-i];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};
