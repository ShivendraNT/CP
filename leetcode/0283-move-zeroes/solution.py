class Solution(object):
    def moveZeroes(self, nums):
        k=0
        nums_temp=nums
        i=0
        while i<len(nums_temp):
            if nums_temp[i]==0:
                nums_temp.pop(i)
                k+=1
            else:
                i+=1
        nums_temp.extend([0]*k)
        for i in range(len(nums_temp)):
            nums[i]=nums_temp[i]
        return nums
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
