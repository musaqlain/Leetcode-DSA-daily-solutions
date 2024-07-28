
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root:
            # p, q are greater than root.val -> root.right
            if p.val > root.val and q.val > root.val:
                root = root.right
            # p, q are smaller than root.val -> root.left
            elif p.val < root.val and q.val < root.val:
                root = root.left
            # p < roo.val < q -> return root
            else: 
                return root