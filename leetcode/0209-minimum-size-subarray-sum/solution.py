class Solution(object):
    def minSubArrayLen(self, target, nums):
        l=0
        total=0
        res=float('inf')
        n=len(nums)
        for r in range(n):
            total+=nums[r]
            while total>=target:
                res=min(res,r-l+1)
                total-=nums[l]
                l+=1
        if res==float('inf'):
            return 0
        return res
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        
