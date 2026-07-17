class Solution {
public:
    int maxDistance(string moves) {
        int xcoord=0;
        int ycoord=0;
        int dash=0;
        for(char c:moves){
            if(c=='_') dash++;
            else if(c=='U') ycoord++;
            else if(c=='D') ycoord--;
            else if(c=='L') xcoord--;
            else xcoord++;
        }
        int ans=abs(ycoord) +abs(xcoord)+dash;
        return ans;
    }
};
