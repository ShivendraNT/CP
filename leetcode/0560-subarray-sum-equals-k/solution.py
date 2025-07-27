class Solution(object):
    def subarraySum(self, nums, k):
        sums=defaultdict(int)
        prefix_sum=0
        res=0
        sums[0]=1
        for n in nums:
            prefix_sum+=n
            res+=sums[prefix_sum-k]
            sums[prefix_sum]+=1
        return res
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
