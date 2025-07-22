# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        curr=[]
        while head:
            curr.append(head.val)
            head=head.next
        if len(curr)==0:
            return None
        curr.pop(len(curr)-n)
        if curr==[]:
            return None
        res=ListNode(0)
        pointer=res
        for i in range(0,len(curr)):
            pointer.next=ListNode(curr[i])
            pointer=pointer.next
        return res.next
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        
