//1190https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
class Solution {
public:
    string reverseParentheses(string s) {
        string str;
        stack<string>stk;

        for (auto& ch : s)
        {
            if (ch == '(')
            {
                stk.push(str);
                str = "";
            }
            else if (ch == ')')
            {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            }
            else
                str += ch;
        }

        return str;
    }
};