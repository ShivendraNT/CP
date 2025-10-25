def merge(nums,low,mid,high):
    cnt=0
    j=mid+1
    for i in range(low,mid+1):
        while(j<=high and nums[i]>2*nums[j]):
            j+=1
        cnt+=(j-(mid+1))
    temp=[]
    left=low
    right=mid+1
    while(left<=mid and right<=high):
        if (nums[left]<=nums[right]):
            temp.append(nums[left])
            left+=1
        else:
            temp.append(nums[right])
            right+=1
    while(left<=mid):
        temp.append(nums[left])
        left+=1
    while(right<=high):
        temp.append(nums[right])
        right+=1
    for i in range(low,high+1):
        nums[i]=temp[i-low]
    return cnt


def mergesort(nums,low,high):
    if (low>=high):
        return 0
    mid=(low+high)//2
    cnt=0
    cnt+=mergesort(nums,low,mid)
    cnt+=mergesort(nums,mid+1,high)
    cnt+=merge(nums,low,mid,high)
    return cnt
class Solution(object):
    def reversePairs(self, nums):
        cnt=mergesort(nums,0,len(nums)-1)
        return cnt
        """
        :type nums: List[int]
        :rtype: int
        """
        
