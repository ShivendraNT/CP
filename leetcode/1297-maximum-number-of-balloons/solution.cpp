class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // {b,a,l,o,n}
        int arr[]={0,0,0,0,0};
        for(char c:text){
            if(c=='b') arr[0]++;
            else if(c=='a') arr[1]++;
            else if(c=='l') arr[2]++;
            else if(c=='o') arr[3]++;
            else if(c=='n') arr[4]++;
        }
        int ans=arr[0];
        for(int i=1;i<5;i++){
            if(i==1 || i==4){
                ans=min(ans,arr[i]);
            }
            else{
                ans=min(ans,arr[i]/2);
            }
        }
        return ans;
    }
};
