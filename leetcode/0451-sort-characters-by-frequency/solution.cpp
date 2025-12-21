class Solution {
public:
    string frequencySort(string s) {
        map<int,vector<char>,greater<int>> count;
        sort(s.begin(),s.end());
        for (int i=0;i<s.size();i++){
            int cnt=1;
            while(i+1<s.size() && s[i]==s[i+1]){
                cnt++;
                i++;
            }
            count[cnt].push_back(s[i]);
        }
        string result="";
        for (const auto &pair : count) {
            int frequency = pair.first;
            const vector<char>& characters = pair.second;

        for (char c : characters) { // New loop: Go through each char with this frequency
            for (int i = 0; i < frequency; i++) {
                result += c;
                }
            }
        }
        return result;


    }
};
