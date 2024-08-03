class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj_list = defaultdict(list)
        indegree = [0] * numCourses
        
        # populate ad_list and indegree array
        for course, prereq in prerequisites:
            adj_list[prereq].append(course)
            indegree[course] += 1
        
        queue = deque([i for i in range(numCourses) if indegree[i] == 0])
        processed_courses = 0
        
        while queue:
            course = queue.popleft()
            processed_courses += 1
            
            for next_course in adj_list[course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    queue.append(next_course)
        
        return processed_courses == numCourses
