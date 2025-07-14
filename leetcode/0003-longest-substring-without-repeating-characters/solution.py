class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if s=='':
            leng=0
        else:
            leng=1
        for i in range(0,len(s)):
            leng2=1
            l=[]
            for j in range(i+1,len(s)):
                if s[i]==s[j] or s[j] in l:
                    break
                elif s[i]!=s[j]:
                    leng2+=1
                    l.append(s[j])
                    if leng2>leng:
                        leng=leng2
        return leng
            
        """
        :type s: str
        :rtype: int
        """
        
