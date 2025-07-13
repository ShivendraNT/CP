class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        d={}
        for i in ransomNote:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
        for i in magazine:
            if i in d:
                if d[i]>0:
                    d[i]=d[i]-1
        x=True
        for i in d:
            if d[i]!=0:
                x=False
                break
        return x
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        
