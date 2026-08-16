class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        int m=lights.size();
        int pen=0;
        for(int i:arrivalTime){
            int r=i%period;
            if(r>=lights[m-1]){
                pen=max(pen,period-r);
            }
        }
        return pen;
    }
};
