class Solution(object):
    def nextGreaterElements(self, nums):
        n=len(nums)
        ans=[-1]*n
        nums=nums*2
        for i in range(n):
            for j in range(i+1,i+n):
                if nums[j]>nums[i]:
                    ans[i]=nums[j]
                    break
        return ans
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
