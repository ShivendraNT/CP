class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+tasks[i];
        }
        long long totalsum=pref[n];
        vector<int> ans;
        int leftptr=0;
        long long rem=tasks[0];
        for(long long currshift:shifts){
            if(currshift<rem){
                rem-=currshift;
                ans.push_back(n-leftptr);
                continue;
            }
            currshift-=rem;
            leftptr++;
            if(leftptr==n){
                ans.push_back(0);
                rem=tasks[0];
                leftptr=0;
                continue;
            }
            long long tillend=pref[n]-pref[leftptr];
            if(currshift>=tillend){
                ans.push_back(0);
                rem=tasks[0];
                leftptr=0;
                continue;
            }
            if(currshift==0){
                rem=tasks[leftptr];
                ans.push_back(leftptr == 0 ? 0 : n - leftptr);
                continue;
            }
            long long target=pref[leftptr]+currshift;
            auto it=upper_bound(pref.begin(),pref.end(),target)-1;
            int idx=distance(pref.begin(),it);
            long long used=pref[idx]-pref[leftptr];
            currshift-=used;
            leftptr=idx;
            rem=tasks[leftptr]-currshift;
            if(rem==0){
                leftptr++;
                if(leftptr==n){
                    ans.push_back(0);
                    rem=tasks[0];
                    leftptr=0;
                }
                else{
                    rem=tasks[leftptr];
                    ans.push_back(n-leftptr);
                }
            }
            else{
                ans.push_back(n-leftptr);
            }
        }
        return ans;
    }
};
