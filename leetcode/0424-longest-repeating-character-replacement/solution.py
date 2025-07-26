class Solution(object):
    def characterReplacement(self, s, k):
        l=0
        res=0
        n=len(s)
        extra={'A':0,'B':0}
        for r in range(n):
            if s[r] in extra.keys():
                extra[s[r]]+=1
            else:
                extra[s[r]]=1
            maxf=max(extra.values())
            if (r-l+1)-maxf>k:
                    extra[s[l]]-=1
                    l+=1
            res=max(res,r-l+1)
        return res
            

        """
        :type s: str
        :type k: int
        :rtype: int
        """
        
