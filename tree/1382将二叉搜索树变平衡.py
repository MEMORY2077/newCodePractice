from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        ans=[]
        def dfs(root:TreeNode):
            if not root:
                return 
            dfs(root.left)
            ans.append(root.val)
            dfs(root.right)
        dfs(root)
        def build(l:int,r:int)->TreeNode:
            mid = (l + r) // 2
            left = None
            right = None
            if l<=mid-1:
                left=build(l,mid-1)
            if mid+1<=r:
                right=build(mid+1,r)
            return TreeNode(ans[mid],left,right)
        return build(0,len(ans)-1)
