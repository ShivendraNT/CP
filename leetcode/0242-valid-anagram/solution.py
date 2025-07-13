class Solution(object):
    def isAnagram(self, s, t):
        p=sorted(s)
        q=sorted(t)
        if p==q:
            return True
        else:
            return False
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
