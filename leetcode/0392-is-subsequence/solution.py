class Solution(object):
    def isSubsequence(self, s, t):
        if not s:
            return True
        s=list(s)
        for i in t:
            if s==[]:
                break
            elif s[0]==i:
                s.remove(i)
        if s==[]:
            return True
        else:
            return False
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
