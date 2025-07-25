# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        def depth(root):
            if not root:
                return 0
            l=depth(root.left)
            if l==-1:
                return -1
            r=depth(root.right)
            if r==-1:
                return -1
            if abs(r-l)>1:
                return -1
            return max(l,r)+1
        return depth(root)!=-1
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        
