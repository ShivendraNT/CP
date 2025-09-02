class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack==needle){
            return 0;
        }
        
        int len= needle.size();
        int len2=haystack.size();
        if (len == 0) return 0;
        for (int i=0;i<=len2-len;i++){
            if (haystack.substr(i,len)==needle){
                return i;
            }
        }
        return -1;
    }
};
