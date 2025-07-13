class Solution(object):
    def firstUniqChar(self, s):
        lettercount={}
        l=[]
        for i in s:
            if i not in lettercount:
                lettercount[i]=1
            else:
                lettercount[i]+=1
        for j in lettercount:
            if lettercount[j]==1:
                l.append(s.index(j))
        if l==[]:
            return -1
        else:
            return min(l)


        """
        :type s: str
        :rtype: int
        """
        
