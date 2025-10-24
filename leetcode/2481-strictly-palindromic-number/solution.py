class Solution(object):
    def isStrictlyPalindromic(self, n):
        for i in range(2,n-1):
            base=[]
            num=n
            while num!=0:
                base.append(str(num%i))
                num//=i
            if base!=reversed(base):
                return False
        return True

        """
        :type n: int
        :rtype: bool
        """
        
