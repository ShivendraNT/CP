class Solution(object):
    def myAtoi(self, s):
        s=s.strip()
        p=''
        x=True
        if s=='':
            return 0
        elif s[0]=='+' and len(s)>=2:
            if s[1] in "1234567890":
                for i in s[1:]:
                    if i in "1234567890":
                        p=p+i
                    else:
                        break
        elif s[0]=='-':
            x=False
            for i in s[1:]:
                if i in "1234567890":
                    p=p+i
                else:
                    break
        elif s[0] in "1234567890":
            for i in s:
                if i in "1234567890":
                    p=p+i
                else:
                    break
        if p!='':
            if x==True:
                p=int(p)
            else:
                p=int(p)*-1
            if p<-2**31:
                return -2**31
            elif p>2**31 -1:
                return 2**31 -1
            else:
                return p
        else:
            return 0
        """
        :type s: str
        :rtype: int
        """
        
