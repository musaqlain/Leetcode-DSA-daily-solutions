class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        hashMap = {val: idx for idx, val in enumerate(inorder)}
        preOrderIndex = [0]  

        def buildBT(preOrderIndex: List[int], inOrderStart: int, inOrderEnd: int) -> Optional[TreeNode]:
            if inOrderStart > inOrderEnd:
                return None

            rootValue = preorder[preOrderIndex[0]]
            root = TreeNode(rootValue)

            inOrderIndex = hashMap[rootValue]

            preOrderIndex[0] += 1

            root.left = buildBT(preOrderIndex, inOrderStart, inOrderIndex - 1)
            root.right = buildBT(preOrderIndex, inOrderIndex + 1, inOrderEnd)

            return root

        return buildBT(preOrderIndex, 0, len(inorder) - 1)