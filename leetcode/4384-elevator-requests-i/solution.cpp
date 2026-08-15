class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time=0;
        int prev=0;
        for(int i:requests){
            time+=abs(prev-i);
            prev=i;
        }
        return time;
    }
};
