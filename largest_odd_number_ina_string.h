// https://leetcode.com/problems/largest-odd-number-in-string/

// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty
// substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:

// Input: num = "4206"
// Output: ""
// Explanation: There are no odd numbers in "4206".
// Example 3:

// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.
// 196 / 196 test cases passed.
// Status: Accepted
// Runtime: 32 ms
// Memory Usage: 15 MB

class Solution
{
public:
    string largestOddNumber(string num)
    {
        auto last = num.end();

        for (auto iter = num.begin(); iter != num.end(); ++iter)
        {
            if ((*iter - '0') % 2 == 1)
            {
                last = iter;
            }
        }

        string res{""};
        if (last != num.end())
        {
            res = string(num.begin(), last + 1);
        }
        return res;
    }
};

// Most elegant one line solution :
// string largestOddNumber(string n)
// {
//     return n.substr(0, n.find_last_of("13579") + 1);
// }

// another simple solution
// class Solution
// {
// public:
//     string largestOddNumber(string num)
//     {
//         int i = num.size() - 1;
//         //Find the rightmost odd number
//         while (i >= 0 and (num[i--] - '0') % 2 == 0)
//             num.pop_back();
//         return num;
//     }
// };
