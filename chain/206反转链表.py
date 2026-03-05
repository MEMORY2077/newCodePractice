from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fakehead = ListNode(-1,head)
        p=head
        q=fakehead
        while p.next is not None:
            t = p.next
            p.next = t.next
            t.next = p
            q.next = t
            q = t
            p = p.next
        return fakehead.next

