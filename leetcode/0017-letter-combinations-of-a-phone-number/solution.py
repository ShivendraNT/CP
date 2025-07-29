class Solution(object):
    def letterCombinations(self, digits):
        if not digits:
            return []
        dicti={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        res=[]
        def backtrack(index,path):
            if index==len(digits):
                res.append(''.join(path))
                return
            letters=dicti[digits[index]]
            for char in letters:
                backtrack(index+1,path+[char])
        backtrack(0,[])
        return res
        """
        :type digits: str
        :rtype: List[str]
        """
        
