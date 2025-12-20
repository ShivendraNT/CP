class Solution(object):
    def reverseWords(self, s):
        reverse=""
        i=0
        while i<len(s):
            if(s[i]==' '):
                i=i+1
                continue
            else:
                word=""
                while(i<len(s) and s[i]!=" "):
                    word=word+s[i]
                    i=i+1
            if(reverse==""):
                reverse=word
            else:
                reverse=word+" "+reverse
            i=i+1
        return reverse
        """
        :type s: str
        :rtype: str
        """
        
