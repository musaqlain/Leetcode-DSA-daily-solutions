class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n+1))  # [0, 1, 2, 3]
        rank = [0] * (n+1) # [0, 0, 0, 0]

        # to find the parent of curr node
        def find(parent, x):
            while(parent[x] != x):
                x = parent[x]

            return x

        def union(parent, rank, x, y):
            rootx = find(parent, x)
            rooty = find(parent, y)

            if rootx != rooty:
                if rank[rootx] >  rank[rooty]:
                    parent[rooty] = rootx
                elif rank[rootx] <  rank[rooty]:
                    parent[rootx] = rooty
                else: 
                    parent[rootx] = rooty
                    rank[rooty] += 1
                return True
            else:
                return False

        for u, v in edges:
            if not union(parent, rank, u, v):
                return [u, v]
        return []