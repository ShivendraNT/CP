class Solution(object):
    def largestOddNumber(self, num):
        s=""
        for i in range(len(num)-1,-1,-1):
            if(int(num[i])%2==1):
                print(num[i])
                s=num[0:i+1]
                break
        return s
        """
        :type num: str
        :rtype: str
        """
