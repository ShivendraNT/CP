class Solution(object):
    def isValid(self, s):
        l=['a']
        d={')':'(','}':'{',']':'['}
        for i in s:
            s=len(l)
            if i in d.keys():
                if l[s-1]!=d[i]:
                    l.append(i)
                else:
                    l.pop(s-1)
            else:
                l.append(i)
            
        if l==['a']:
            return True
        else:
            return False
                
        """
        :type s: str
        :rtype: bool
        """
        
