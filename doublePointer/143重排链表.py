from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return 
        fast = slow = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        head2 =slow.next
        slow.next = None
        prev,curr = None,head2
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        head2 = prev
        p = head
        q = head2
        while q:
            next1 = p.next
            next2 = q.next
            p.next = q
            q.next = next1
            p = next1
            q = next2
        return head
