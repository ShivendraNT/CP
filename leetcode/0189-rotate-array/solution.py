class Solution(object):
    def rotate(self, nums, k):
        n=len(nums)
        final=[0]*n
        for i in range(0,n):
            if (i + k)>=n:
                final[(i+k)%n]=nums[i]
            else:
                final[i+k]=nums[i]
        for i in range(n):
            nums[i]=final[i]
        return nums

        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
