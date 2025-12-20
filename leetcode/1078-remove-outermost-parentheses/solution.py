class Solution(object):
    def removeOuterParentheses(self, s):
        string=""
        stack=[]
        for i in s:
            if (i=="("):
                if (stack==[]):
                    stack.append(i)
                    continue
                else:
                    string=string+i
                    stack.append(i)
            else:
                stack.pop()
                if(len(stack)==0):
                    continue
                string=string+i
                    
        return string

        """
        :type s: str
        :rtype: str
        """
        
