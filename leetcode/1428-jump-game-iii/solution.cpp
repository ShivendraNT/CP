class Solution {
public:
    bool Reach(vector<int>&arr,int start,vector<int>&visited){
        if(start>=arr.size()){
            return false;
        }
        else if(start<0){
            return false;
        }
        if(arr[start]==0){
            return true;
        }
        if(visited[start]==1){
            return false;
        }
        visited[start]=1;
        if(Reach(arr,start+arr[start],visited) || Reach(arr,start-arr[start],visited)){
            return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        return Reach(arr,start,visited);
    } 
};
