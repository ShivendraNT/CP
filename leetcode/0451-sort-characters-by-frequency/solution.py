class Solution(object):
    def frequencySort(self, s):
        count={}
        for i in s:
            if (i not in count.keys()):
                count[i]=1
            else:
                count[i]+=1
        sort_key=sorted(count.items(),key=lambda item:item[1],reverse=True)
        string=[]
        for i in sort_key:
            string.append(i[0]*i[1])
        return "".join(string)
        """
        :type s: str
        :rtype: str
        """
        
