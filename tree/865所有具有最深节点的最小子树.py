from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        max_depth = 0
        res = None
        def dfs1(root,depth) -> int:
            nonlocal max_depth,res
            if not root:
                max_depth = max(max_depth,depth)
                return depth
            left = dfs1(root.left,depth+1)
            right = dfs1(root.right,depth+1)
            if left == max_depth and right == max_depth:
                res = root
            return max(left,right)
        dfs1(root,0)
        return res

        