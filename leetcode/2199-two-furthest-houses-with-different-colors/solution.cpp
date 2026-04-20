class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                while(j<n-1 && colors[j]==colors[j+1]){
                    j++;
                }
                if(colors[j]!=colors[i]){
                    maxi=max(maxi,j-i);
                }
                
            }
            while(i<n-1 && colors[i]==colors[i+1]){
                i++;
            }
        }
        return maxi;
    }
};
