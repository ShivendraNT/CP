class Solution(object):
    def isHappy(self, n):
        n=str(n)
        j=0
        while j<100:
            d={}
            for i in range(0,len(n)):
                d[i]=int(n[i])**2
            s=sum(d.values())
            x=False
            if s==1:
                x=True
                break
            else:
                n=str(s)
            j+=1
        return x
        """
        :type n: int
        :rtype: bool
        """
        
