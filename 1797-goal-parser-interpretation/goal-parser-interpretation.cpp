#include <string>

class Solution {
public:
    std::string interpret(std::string command) {
        std::string result;

        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                result += 'G';
            } else if (command[i] == '(' && command[i + 1] == ')') {
                result += 'o';
                ++i; // Skip the closing parenthesis
            } else if (command[i] == '(' && command[i + 1] == 'a') {
                result += "al";
                i += 3; // Skip "(al)"
            }
        }

        return result;
    }
};
