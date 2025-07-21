class Solution(object):
    def containsDuplicate(self, nums):
        d={}
        for i in nums:
            if i not in d:
                d[i]=1
            else:
                return True
        return False
        """
        :type nums: List[int]
        :rtype: bool
        """
        
