# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        self.levels={}
        def dfs(node,level):
            if not node:
                return None
            if level not in self.levels:
                self.levels[level]=[]
            self.levels[level].append(node.val)
            
            dfs(node.left,level+1)
            dfs(node.right,level+1)
        dfs(root,0)
        return [self.levels[i] for i in sorted(self.levels.keys())]

        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        
