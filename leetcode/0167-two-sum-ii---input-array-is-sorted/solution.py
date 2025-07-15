class Solution(object):
    def twoSum(self, numbers, target):
        seen={}
        for i,val in enumerate(numbers):
            if target-val in seen:
                return [seen[target-val]+1,i+1]
            seen[val]=i
                
            
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        
