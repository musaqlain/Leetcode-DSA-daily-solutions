class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (auto& i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                int operand2 = stk.top();
                stk.pop();
                int operand1 = stk.top();
                stk.pop();

                if (i == "+")
                    stk.push(operand1 + operand2);
                else if (i == "-")
                    stk.push(operand1 - operand2);
                else if (i == "*")
                    stk.push(operand1 * operand2);
                else if (i == "/")
                    stk.push(operand1 / operand2);

            } else {
                stk.push(stoi(i));
            }
        }
        return stk.top();
    }
};