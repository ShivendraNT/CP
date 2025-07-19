class Solution(object):
    def dominantIndex(self, nums):
        k=sorted(nums)
        if k[-2]==0:
            return nums.index(k[-1])
        elif k[-1]//k[-2]>=2:
            return nums.index(k[-1])
        else:
            return -1
        """
        :type nums: List[int]
        :rtype: int
        """
        
