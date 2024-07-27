class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # hash inorder
        hashMap = {val: idx for idx, val in enumerate(inorder)}
        self.preorderIndex = 0

        def buildBT(inOrderStart: int, inOrderEnd: int) -> Optional[TreeNode]:
            # base condition
            if inOrderStart > inOrderEnd:
                return None

            # find root
            rootVal = preorder[self.preorderIndex]
            self.preorderIndex += 1

            # create a tree with that root
            root = TreeNode(rootVal)

            # check that root in out hash table
            inOrderIndex = hashMap[rootVal]

            # recursively run at left
            root.left = buildBT(inOrderStart, inOrderIndex - 1)

            # recursively run at right
            root.right = buildBT(inOrderIndex + 1, inOrderEnd)

            return root
        
        return buildBT(0, len(inorder) - 1)

        
        