class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int tx=target[0];
        int ty=target[1];
        int mindist=INT_MAX;
        int ans=-1;
        for(int i=0;i<drones.size();i++){
            int x=drones[i][0];
            int y=drones[i][1];
            int r=drones[i][2];
            int dist=abs(x-tx)+abs(y-ty);
            if(dist<=r && dist<mindist){
                mindist=dist;
                ans=i;
            }
        }
        return ans;
    }
};
