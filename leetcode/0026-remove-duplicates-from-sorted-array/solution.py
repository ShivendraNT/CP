class Solution(object):
    def removeDuplicates(self, nums):
        k=0
        for i in nums:
            if i not in nums[:k]:
                nums[k]=i
                k+=1
        return k
        """
        :type nums: List[int]
        :rtype: int
        """
        
