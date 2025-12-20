class Solution(object):
    def rotateString(self, s, goal):
        for i in range(len(s)):
            if(s==goal):
                return True
            s=s[1:len(s)]+s[0]
        return False
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        
