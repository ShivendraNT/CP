class Solution(object):
    def isPowerOfTwo(self, n):
        for i in range(0,31):
            if n==2**i:
                return True
        return False
        """
        :type n: int
        :rtype: bool
        """
        
