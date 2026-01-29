class Solution(object):
    def getRow(self, rowIndex):
        row=[1]
        b=[]
        if(rowIndex==0):
            return row
        elif(rowIndex==1):
            return [1,1]
        else:
            b.append(row)
            row=[1,1]
            b.append(row)
            for i in range(2,rowIndex+1):
                row=[]
                for j in range(0,i+1):
                    if(j==0 or j==i):
                        row.append(1)
                    else:
                        row.append(b[i-1][j-1]+b[i-1][j])
                b.append(row)
        return b[-1]
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        
