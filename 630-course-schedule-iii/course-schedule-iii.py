import heapq

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x:(x[1], x[0]))

        time = 0
        max_heap = []

        for duration, lastDay in courses:
            # check single duration of the current course
            if duration <= lastDay:
                # ovrall duration
                if time + duration <= lastDay:
                    # take
                    # min - heap queue
                    heapq.heappush(max_heap, -duration)
                    time += duration
                else:
                    # swap
                    if max_heap and -max_heap[0] > duration:
                        time -= -heapq.heappop(max_heap)
                        heapq.heappush(max_heap, -duration)
                        time += duration


        return len(max_heap)



        