class Solution(object):
    def search(self, nums, target):
        s=sorted(nums)
        diff=nums.index(s[0])%len(s)
        L=0
        R=len(s)-1
        while L<=R:
            M=L+(R-L)//2
            if s[M]==target:
                return (M+diff)%len(s)
            elif s[M]<target:
                L=M+1
            else:
                R=M-1
        return -1
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
