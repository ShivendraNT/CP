class Solution(object):
    def containsDuplicate(self, nums):
        count=set(nums)
        if len(count)==len(nums):
            return False
        return True
        """
        :type nums: List[int]
        :rtype: bool
        """
        
