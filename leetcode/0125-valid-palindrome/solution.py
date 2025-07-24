class Solution(object):
    def isPalindrome(self, s):
        k=[]
        for i in s:
            if i.isalnum():
                k.append(i.lower())
        f=''.join(k)
        return f==f[::-1]
        """
        :type s: str
        :rtype: bool
        """
        
