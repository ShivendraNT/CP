class Solution {
int findstart(vector<int>& a,int target){
    int left=0;
    int right=a.size()-1;
    int start=-1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if (a[mid]==target){
            start=mid;
            right=mid-1;
        }else if (target>a[mid]){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return start;
}
int findend(vector<int>& a ,int target){
    int left=0;
    int right=a.size()-1;
    int end=-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if (a[mid]==target){
            end=mid;
            left=mid+1;
        }else if (target>a[mid]){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return end;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        if (nums.size()==0){
            return ans;
        }
        ans[0]=findstart(nums,target);
        ans[1]=findend(nums,target);
        return ans;
    }
};
