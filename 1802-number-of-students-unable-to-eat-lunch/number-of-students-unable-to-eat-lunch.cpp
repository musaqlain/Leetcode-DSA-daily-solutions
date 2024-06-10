class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        const int total = students.size();
        stack<int> s1;
        queue<int> q;

        for (int i=total-1; i>=0; i--) {
            s1.push(sandwiches[i]);
            q.push(students[i]);
        }

        int notEated = 0, eated = 0;

        while (!q.empty()) {
            if (s1.top() == q.front()) {
                q.pop(), s1.pop();
                eated++;
                notEated = 0;
            } else {
                int x = q.front();
                q.pop(); 
                q.push(x); 
                notEated++;              
            }
            if (notEated == total - eated) break;
        }

        return notEated;
    }
};
