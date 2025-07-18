class Solution(object):
    def searchRange(self, nums, target):
        n=[-1,-1]
        if nums==[]:
            return n
        elif target in nums:
            n[0]=nums.index(target)
            n[1]=n[0]+nums.count(target)-1
            return n
        else:
            return n

        
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
