from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(root:TreeNode)->int:
            if not root:
                return 0
            return max(height(root.left),height(root.right))+1
        if not root:
            return True
        res=abs(height(root.left)-height(root.right))
        return res<=1 and isBalanced(root.left) and isBalanced(root.right)
