from copy import deepcopy
class Solution(object):
    def rotate(self, matrix):
        temp=deepcopy(matrix[::-1])
        print(temp)
        n=len(matrix)
        for i in range(n):
            for j in range(n):
                matrix[i][j]=temp[j][i]
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        
