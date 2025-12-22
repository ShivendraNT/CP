class Solution(object):
    def maxDepth(self, s):
        maxs=0
        stack=[]
        for i in s:
            if (i=='('):
                stack.append(i)
            else:
                if(len(stack)>0 and i==")"):
                    stack.pop()
            if(len(stack)>maxs):
                maxs=len(stack)
        return maxs
        """
        :type s: str
        :rtype: int
        """
        
