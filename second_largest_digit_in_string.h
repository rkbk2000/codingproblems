// Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
// An alphanumeric string is a string consisting of lowercase English letters and digits.

// Example 1:

// Input: s = "dfa12321afd"
// Output: 2
// Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
// Example 2:

// Input: s = "abc1111"
// Output: -1
// Explanation: The digits that appear in s are [1]. There is no second largest digit.

// Constraints:

// 1 <= s.length <= 500
// s consists of only lowercase English letters and/or digits.
// Runtime: 4 ms, faster than 78.32% of C++ online submissions for Second Largest Digit in a String.
// Memory Usage: 6.9 MB, less than 26.87% of C++ online submissions for Second Largest Digit in a String.

// test cases:
// "sjhtz8344"
// "dfa12321afd"
// "abc1111"
// "abc"
// "123"
// "a99"
// "0"
// "01"
// "ab"

// Output:
// 4
// 2
// -1
// -1
// 2
// -1
// -1
// 0
// -1

// https://leetcode.com/problems/second-largest-digit-in-a-string/submissions/
class Solution1
{
public:
    int secondHighest(string s)
    {
        set<int> digits;

        for (auto &c : s)
        {
            if (isdigit(c))
            {
                digits.insert(c - '0');
                if (digits.size() == 10)
                {
                    // No need to check further, we have all digits
                    break;
                }
            }
        }

        if (digits.size() > 1)
        {
            auto it = digits.rbegin();
            ++it;
            return *it;
        }
        return -1;
    }
};

// Another solution
// Runtime: 4 ms, faster than 78.32% of C++ online submissions for Second Largest Digit in a String.
// Memory Usage: 6.8 MB, less than 49.91% of C++ online submissions for Second Largest Digit in a String.

class Solution
{
public:
    int secondHighest(string s)
    {
        auto first = -1, second = -1;

        for (auto &c : s)
        {
            if (isdigit(c))
            {
                auto dig = c - '0';
                if (dig > first)
                {
                    second = first;
                    first = dig;
                }
                else if ((dig > second) && dig != first)
                {
                    second = dig;
                }
            }
        }

        if (second == -1 || first == -1)
        {
            return -1;
        }
        return second;
    }
};