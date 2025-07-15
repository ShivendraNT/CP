class Solution(object):
    def majorityElement(self, nums):
        dic={}
        for i in nums:
            if i in dic:
                dic[i]+=1
            else:
                dic[i]=1
        for key,values in dic.items():
            if values > len(nums)/2:
                return key
        """
        :type nums: List[int]
        :rtype: int
        """
