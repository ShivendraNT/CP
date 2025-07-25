# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        self.maxdepth=0
        def diam(node):
            if not node:
                return 0
            l=diam(node.left)
            r=diam(node.right)
            if l+r>self.maxdepth:
                self.maxdepth=l+r
            return max(l,r)+1
        diam(root)
        return self.maxdepth
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        
