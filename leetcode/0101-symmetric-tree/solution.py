# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        def check(node1,node2):
            if not node1 and not node2:
                return True
            elif not node1 or not node2:
                return False
            l=check(node1.left,node2.right)
            if l==False:
                return False
            r=check(node1.right,node2.left)
            if r==False:
                return False
            if node1.val==node2.val:
                return True
            return False
        node1=root.left
        node2=root.right
        if not node1 and not node2:
            return True
        if not node1 or not node2:
            return False
        if node1.val!=node2.val:
            return False
        return check(node1,node2)
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        
