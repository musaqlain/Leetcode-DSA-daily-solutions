class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        preReqTable = {c:[] for c in range(numCourses)}
        # populate these empty arrays
        for crs, preq in prerequisites:
            preReqTable[crs].append(preq)
        
        cycle, visit = set(), set()
        output = []

        # visted
        # visiting
        # untouched

        def dfs(crs):
            # base condition
            # if cycle exists
                # return []
            if crs in cycle:
                return False
            if crs in output:
                return True
            # then we will continue forward

            # we will add out crs
            cycle.add(crs)

            for pre in preReqTable[crs]:
                if dfs(pre) == False:
                    return False
            cycle.remove(crs)
            output.append(crs)
            return True

        for crs in range(numCourses):
            if dfs(crs) == False:
                    return []
        return output

        