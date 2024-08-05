class Solution:
    def findOrder(self, nums: int, preq: List[List[int]]) -> List[int]:
        adj_list = defaultdict(list)
        indegree = [0] * nums

        for crs, p in preq:
            adj_list[p].append(crs)
            indegree[crs] += 1
        
        q = deque([i for i in range(nums) if indegree[i] == 0])

        # Kahn's Algo
        ans = []

        while q:
            crs = q.popleft()
            ans.append(crs)

            for n in adj_list[crs]:
                indegree[n] -= 1
                if indegree[n] == 0:
                    q.append(n)

        # Check if the entire graph has been processed
        if len(ans) == nums:
            return ans
        else:
            return []