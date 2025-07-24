# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        def check(p,q):
            if not p and not q:
                return True
            elif not p or not q:
                return False
            if p.val!=q.val:
                return False
            else:
                if check(p.left,q.left) != True or check(p.right,q.right) != True:
                    return False
            return True
        return check(p,q)
        """
        :type p: Optional[TreeNode]
        :type q: Optional[TreeNode]
        :rtype: bool
        """
        
