#include <iostream>
#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int len=prefix.length();
        int strslen=strs.size();
        for (int i=0;i<strslen;i++){
            while (strs[i].find(prefix) !=0){
                prefix=prefix.substr(0,--len);
                if (prefix==""){
                    return "";
                }
            }
            }
        return prefix;
    }
};
