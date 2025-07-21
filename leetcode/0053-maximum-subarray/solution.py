class Solution(object):
    def maxSubArray(self, nums):
        total=curr_sum=nums[0]

        for num in nums[1:]:
            curr_sum=max(num,curr_sum+num)
            total=max(total,curr_sum)
        return total
        """
        :type nums: List[int]
        :rtype: int
        """
        
