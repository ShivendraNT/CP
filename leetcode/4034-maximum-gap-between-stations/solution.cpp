class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        int j=0;
        vector<int> left(n);
        for(int i=0;i<n;i++){
            while(station[j]!=skill[i]){
                j++;
            }
            left[i]=j;
            j++;
        }
        j=m-1;
        vector<int> right(n);
        for(int i=n-1;i>=0;i--){
            while(station[j]!=skill[i]){
                j--;
            }
            right[i]=j;
            j--;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,right[i]-left[i-1]);
        }
        return ans;
    }
};
