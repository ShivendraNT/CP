class Solution(object):
    def isIsomorphic(self, s, t):
        if (len(s)!=len(t)):
            return False
        map={}
        values=[]
        for i in range(len(s)):
            if (s[i] in map.keys()):
                if(map[s[i]]!=t[i]):
                    return False
            else:
                map[s[i]]=t[i]
                if (t[i] in values):
                    return False
                values.append(t[i])
        return True
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
