class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        # count the students
        count_student = Counter(students) 

        total = len(sandwiches)

        # iterate on stack/ sandwiches
        for s in sandwiches:
            if count_student[s] > 0:
                count_student[s] -= 1
                total -= 1
            else: 
                return total

        return 0





        # problem statement done
        # brute force solution done
        # optimized soluion done
        # code
