class Solution {
public:
    bool isValid(string s) {
            if (s.length() & 1 == 1) {
                return false;
            }

        unordered_map<char, char> brackets {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        stack<char> stk;

        for (char bracket : s) {
            if (bracket == '(' || bracket == '[' || bracket == '{')
                stk.push(bracket);
            else {
                if (stk.empty() || bracket != brackets[stk.top()])
                    return false;
                stk.pop();
            }
        }

        // We've paired all brackets to each other
        if (stk.empty())
            return true;
        
        // We didn't :(
        return false;
    }
};