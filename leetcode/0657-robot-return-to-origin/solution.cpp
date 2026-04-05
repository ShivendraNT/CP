class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.size()%2==1){
            return false;
        }
        int up=0;
        int left=0;
        for(char c : moves){
            if(c=='U') up++;
            else if(c=='D') up--;
            else if(c=='L') left++;
            else left--;
        }
        if(up==0 && left==0) return true;
        return false;
    }
};
