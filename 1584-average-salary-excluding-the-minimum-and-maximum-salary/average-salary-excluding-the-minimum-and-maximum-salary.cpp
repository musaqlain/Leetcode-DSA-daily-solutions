class Solution {
public:
    double average(vector<int>& salary) {
        const int n = salary.size();
        sort(salary.begin(), salary.end());
        double res = 0.0;
        for (int i:salary)
            res += i;
        
        res = (res-salary[0]-salary[n-1])/(n-2);
        return res;
    }
};