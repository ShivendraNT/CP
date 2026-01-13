class Solution(object):
    def majorityElement(self, nums):
        n=len(nums)
        n=int(n/3)
        ans=[]
        count={}
        for i in nums:
            if i not in count:
                count[i]=1
                continue
            count[i]+=1
        for key,val in count.items():
            if (val>n):
                ans.append(key)
        return ans
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
