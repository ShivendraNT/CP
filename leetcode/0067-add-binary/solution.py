class Solution(object):
    def addBinary(self, a, b):
        ans=int(a,2) + int(b,2)
        return bin(ans)[2:]
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
