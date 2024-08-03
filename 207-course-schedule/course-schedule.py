class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # hash table
        preMap = {i:[] for i in range(numCourses)}
        # populate the table
        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        visitSet = set()
        # define dfs function
        def dfs(crs):
            # base conditions
            if crs in visitSet:
                return False
            if preMap[crs] == []:
                return True
            
            visitSet.add(crs)
            for pre in preMap[crs]:
                if not dfs(pre): return False
            visitSet.remove(crs)
            preMap[crs] = []
            return True

        for crs in range(numCourses):
            if not dfs(crs): return False
        return True

