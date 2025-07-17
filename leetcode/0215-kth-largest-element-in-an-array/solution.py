class Solution(object):
    def findKthLargest(self, nums, k):
        num=sorted(nums)
        n=len(nums)
        return num[n-k]
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
