class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Traverse the tree
        while root:
            # If both p and q are greater than root, then LCA lies in the right
            if p.val > root.val and q.val > root.val:
                root = root.right
            # If both p and q are smaller than root, then LCA lies in the left
            elif p.val < root.val and q.val < root.val:
                root = root.left
            # We have found the split point, i.e., the LCA node
            else:
                return root