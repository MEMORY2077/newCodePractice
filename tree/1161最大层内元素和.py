from typing import Optional, Deque
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        dq = Deque()
        result = list()
        dq.append(root)
        while len(dq) != 0:
            sum = 0
            l = len(dq)
            for i in range(0,l):
                now = dq.popleft()
                sum += now.val
                if now.left != None:
                    dq.append(now.left)
                if now.right !=None:
                    dq.append(now.right)
            result.append(sum)
        maximum = 0
        for i in range(0,len(result)):
            if result[i]>result[maximum]:
                maximum = i
        return maximum+1