class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None
        
        # Root is the first element in the preorder traversal
        root_val = preorder.pop(0)
        root = TreeNode(root_val)

        # Find the index of root in the inorder traversal
        root_index = inorder.index(root_val)

        # Recursively construct the left and right subtree
        root.left = self.buildTree(preorder, inorder[:root_index])
        root.right = self.buildTree(preorder, inorder[root_index+1:])

        return root


        