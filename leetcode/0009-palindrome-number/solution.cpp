class Solution {
public:
    bool isPalindrome(int x) {
        string str=to_string(x);
        string rev=to_string(x);
        reverse(rev.begin(),rev.end());
        if (rev==str){
            return true;
        }
        return false;
    }
};
