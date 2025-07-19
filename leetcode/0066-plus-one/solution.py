class Solution(object):
    def plusOne(self, digits):
        if digits[-1] != 9:
            digits[-1] = digits[-1] + 1
        elif len(digits)==1:
            digits=[1,0]
        else:
            for i in range(len(digits)-1,-1,-1):
                if digits[i]==9 and i==0:
                    digits[i]=1
                    digits.append(0)
                elif digits[i]==9:
                    digits[i]=0
                else:
                    digits[i]=digits[i]+1
                    break
        return digits

        """
        :type digits: List[int]
        :rtype: List[int]
        """
        
