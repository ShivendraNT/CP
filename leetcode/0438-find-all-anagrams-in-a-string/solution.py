from collections import Counter
class Solution(object):
    def findAnagrams(self, s, p):
        n=len(p)
        p_count=Counter(p)
        s_count=Counter(s[:n])
        l=[]
        if p_count==s_count:
            l.append(0)
        for i in range(n,len(s)):
            s_count[s[i-n]]-=1
            if s_count[s[i-n]]==0:
                del s_count[s[i-n]]
            s_count[s[i]]+=1
            if s_count==p_count:
                l.append(i-n+1)

        return l
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        
