# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        dummy=ListNode()
        tail=dummy
        print(tail)
        rem=0
        while l1 or l2:
            if l1 and l2:
                sum=l1.val + l2.val +rem
                l1=l1.next
                l2=l2.next
            elif l1:
                sum=l1.val + rem
                l1=l1.next
            else:
                sum=l2.val+rem
                l2=l2.next
            tail.next=ListNode(sum%10)
            rem=sum//10
            tail=tail.next
        if rem==0:
            return dummy.next
        else:
            tail.next=ListNode(rem)
            return dummy.next
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        
