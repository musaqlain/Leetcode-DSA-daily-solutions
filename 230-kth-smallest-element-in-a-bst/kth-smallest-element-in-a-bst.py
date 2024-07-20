class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.result = -1
        self.count = 0
        
        def dfs(node: Optional[TreeNode]) -> None:
            if not node or self.result != -1:
                return
            
            # Traverse the left subtree
            dfs(node.left)
            
            # Process the current node
            self.count += 1
            if self.count == k:
                self.result = node.val
                return
            
            # Traverse the right subtree
            dfs(node.right)
        
        # Start the DFS from the root
        dfs(root)
        return self.result