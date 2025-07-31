from collections import Counter
class Solution(object):
    def isAnagram(self, s, t):
        p=Counter(s)
        q=Counter(t)
        if p==q:
            return True
        return False
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
