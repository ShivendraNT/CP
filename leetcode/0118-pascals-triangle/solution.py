class Solution(object):
    def generate(self, numRows):
        ans=[]
        row=[1]
        ans.append(row)
        if (numRows==1):
            return ans
        row=[1,1]
        ans.append(row)
        if(numRows==2):
            return ans
        for i in range(2,numRows):
            row=[]
            for j in range(0,i+1):
                if(j==0 or j==i):
                    row.append(1)
                else:
                    print(i,j)
                    row.append(ans[i-1][j-1]+ans[i-1][j])
            ans.append(row)
        return ans
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        
