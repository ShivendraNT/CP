class Solution(object):
    def isValidSudoku(self, board):
        seen=set()
        #Rows
        for i in range(9):
            #Columns
            for j in range(9):
                num=board[i][j]
                if num!='.':
                    row_tag=(i,num)
                    col_tag=(num,j)
                    box_tag=(i//3,j//3,num)
                    if row_tag in seen or col_tag in seen or box_tag in seen:
                        return False
                    seen.add(row_tag)
                    seen.add(col_tag)
                    seen.add(box_tag)
        return True
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        
