class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, ans = 0, r = 0;
        int arr[]={0,0,0};
        
        while (r < s.size()) {
            arr[s[r]-'a']++;
            
            while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {
                ans += (s.size() - r);
                arr[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
