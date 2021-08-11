// Given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// https://leetcode.com/problems/maximum-69-number/

// Example 1:

// Input: num = 9669
// Output: 9969
// Explanation:
// Changing the first digit results in 6669.
// Changing the second digit results in 9969.
// Changing the third digit results in 9699.
// Changing the fourth digit results in 9666.
// The maximum number is 9969.
// Example 2:

// Input: num = 9996
// Output: 9999
// Explanation: Changing the last digit 6 to 9 results in the maximum number.
// Example 3:

// Input: num = 9999
// Output: 9999
// Explanation: It is better not to apply any change.

// Constraints:

// 1 <= num <= 10^4
// num's digits are 6 or 9

// Hints
// Convert the number in an array of its digits.
// Brute force on every digit to get the maximum number.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
// Memory Usage: 6 MB, less than 44.98% of C++ online submissions for Maximum 69 Number.

class Solution
{
public:
    int maximum69Number(int num)
    {
        auto s = std::to_string(num);
        for (auto &c : s)
        {
            if (c == '6')
            {
                c = '9';
                break;
            }
        }
        return std::atoi(s.c_str());
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
// Memory Usage: 6 MB, less than 17.39% of C++ online submissions for Maximum 69 Number.
// Another solution
// 6 - >9 = 6+3, 69->99 = 69+30 etc.
class SolutionOneConv
{
public:
    int maximum69Number(int num)
    {
        auto s = std::to_string(num);
        int pos = s.size() - 1;
        for (auto &c : s)
        {
            if (c == '6')
            {
                c = '9';
                break;
            }
            --pos;
        }
        return num + ((pos >= 0) ? (3 * pow(10, pos)) : 0);
    }
};