class Solution(object):
    def intToRoman(self, num):
        s=""
        i=num//1000
        s=s+'M'*i
        num=num-1000*i
        if num>=900:
            s=s+'CM'
            num=num-900
        elif num>=500:
            s=s+"D"
            num=num-500
            i=num//100
            s=s+"C"*i
            num=num-100*i
        elif num>=400:
            s=s+"CD"
            num=num-400
        else:
            i=num//100
            s=s+"C"*i
            num=num-100*i
        if num>=90:
            s=s+'XC'
            num=num-90
        elif num>=50:
            s=s+"L"
            num=num-50
            i=num//10
            s=s+"X"*i
            num=num-10*i
        elif num>=40:
            s=s+"XL"
            num=num-40
        else:
            i=num//10
            s=s+"X"*i
            num=num-10*i
        if num>=9:
            s=s+'IX'
            num=num-9
        elif num>=5:
            s=s+"V"
            num=num-5
            s=s+"I"*num
            num=0
        elif num>=4:
            s=s+"IV"
            num=num-4
        else:
            s=s+"I"*num
            num=0
        return s
        """
        :type num: int
        :rtype: str
        """
        
