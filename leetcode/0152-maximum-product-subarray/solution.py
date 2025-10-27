class Solution(object):
    def maxProduct(self, nums):
        prefix=1
        suffix=1
        n=len(nums)
        maxi=-9999999
        for i in range(n):
            if (prefix==0):
                prefix=1
            if (suffix==0):
                suffix=1
            prefix*=nums[i]
            suffix*=nums[n-i-1]
            maxi=max(maxi,prefix,suffix)
        return maxi  
        """
        :type nums: List[int]
        :rtype: int
        """
        
