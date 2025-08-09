class Solution(object):
    def longestPalindrome(self, s):
        self.max_elem=''
        self.max_length=0
        def expand(left,right):
            while left>=0 and right<len(s) and s[left]==s[right]:
                if right-left+1>self.max_length:
                    self.max_elem=s[left:right+1]
                    self.max_length=right-left+1
                left-=1
                right+=1
        for i in range(len(s)):
            expand(i,i)
            expand(i,i+1)
        return self.max_elem
        """
        :type s: str
        :rtype: str
        """
        
