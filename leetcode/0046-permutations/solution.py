class Solution(object):
    def permute(self, nums):
        res=[]
        temp=[]
        n=len(nums)
        used=[False]*n
        def backtrack():
            if len(temp)==n:
                res.append(temp[:])
                return 
            for i in range(n):
                if not used[i]:
                    used[i]=True
                    temp.append(nums[i])
                    backtrack()
                    temp.pop()
                    used[i]=False
        backtrack()
        return res
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
