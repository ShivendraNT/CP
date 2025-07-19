class Solution(object):
    def lengthOfLastWord(self, s):
        s=s.strip().split()
        if s==[]:
            return 0
        else:
            return len(s[-1])
        """
        :type s: str
        :rtype: int
        """
        
