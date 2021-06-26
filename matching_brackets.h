// Test case:
// "()"
// "()[]{}"
// "(]"
// "([)]"
// "{[]}"
// "["
// "]"

// Output:
// true
// true
// false
// false
// true
// false
// false
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.2 MB, less than 92.32% of C++ online submissions for Valid Parentheses.

// https://leetcode.com/problems/valid-parentheses/submissions/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;

        auto matching = [&](char e)
        {
            if (!brackets.empty() && (e == brackets.top()))
            {
                brackets.pop();
                return true;
            }
            return false;
        };

        for (auto &c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                brackets.push(c);
                break;
            case ')':
                if (!matching('('))
                {
                    return false;
                }
                break;
            case ']':
                if (!matching('['))
                {
                    return false;
                }
                break;
            case '}':
                if (!matching('{'))
                {
                    return false;
                }
                break;
            }
        }
        return brackets.empty() ? true : false;
    }
};