from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        count1 = 0
        count2 = 0
        p = headA
        q = headB
        while p != None:
            count1 += 1
            p = p.next
        while q != None:
            count2 += 1
            q = q.next
        if count1 < count2:
            p = headB
            q = headA
            t = count1
            count1 = count2
            count2 = t
        else:
            p = headA
            q = headB
        for i in range(count1-count2):
            p = p.next
        while p is not None and q is not None:
            if p == q:
                return p
            p = p.next
            q = q.next
        return None
        