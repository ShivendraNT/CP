class Solution(object):
    def subsets(self, nums):
        sol=[]
        temp=[]
        n=len(nums)
        def backtrack(i):
            if i==n:
                sol.append(temp[:])
                return
            
            backtrack(i+1)
            temp.append(nums[i])
            backtrack(i+1)
            temp.pop()
        backtrack(0)
        return sol
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
