class Solution(object):
    def reverse(self, x):
        s=str(x)
        dest=''
        if s[0]=='-':
            for n in range(len(s)-1,0,-1):
                dest=dest+s[n]
            ans=int(dest)

            if ans< -2**31 or ans> 2**31 -1:
                return 0
            else:
                return ans*-1
            
        else:
            for n in range(len(s)-1,-1,-1):
                dest=dest+s[n]
            ans=int(dest)
            if ans< -2**31 or ans> 2**31 -1:
                return 0
            else:
                return ans


        """
        :type x: int
        :rtype: int
        """
        
