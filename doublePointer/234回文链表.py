from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = slow = head
        count = 0
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
            count +=1
        head2 = None
        if fast is not None:
            head2 = ListNode(slow.val)
            head2.next = slow.next
            slow.next = None
        else:
            head2 = slow
        head1 = head
        fakehead1 = ListNode(-1, head1)
        fakehead2 = ListNode(-1, head2)
        p = head2
        while p.next is not None:
            t = p.next
            p.next = t.next
            t.next=fakehead2.next
            fakehead2.next = t
        p = fakehead2
        q = fakehead1
        while p is not None:
            if p.val !=q.val:
                return False
            p = p.next
            q = q.next
        return True

        
