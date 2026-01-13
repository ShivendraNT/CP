class Solution(object):
    def longestConsecutive(self, nums):
        nums.sort()
        n=len(nums)
        ctr=1
        maxsize=1
        if(n==0):
            return 0
        for i in range(n-1):
            if(nums[i]==nums[i+1]):
                continue
            elif(nums[i]+1==nums[i+1]):
                ctr+=1
            else:
                ctr=1
            maxsize=max(maxsize,ctr)
            
        return maxsize
        """
        :type nums: List[int]
        :rtype: int
        """
        
