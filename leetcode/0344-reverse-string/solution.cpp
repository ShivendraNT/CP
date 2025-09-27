class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        cout<<len;
        char temp;
        for (int i=0;i<len/2;i++){
            temp=s[len-i-1];
            s[len-i-1]=s[i];
            s[i]=temp;
        }
    }
};
