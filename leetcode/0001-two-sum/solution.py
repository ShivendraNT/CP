class Solution(object):
    def twoSum(self, nums, target):
        d={}
        i=0
        while i<len(nums):
            if nums[i] in d.values():
                for key,value in d.items():
                    if value==nums[i]:
                        return [key,i]
            d[i]=target-nums[i]
            i+=1
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
