// Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

// A word is a maximal substring consisting of non-space characters only.

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Example 2:

// Input: s = " "
// Output: 0

// Constraints:

// 1 <= s.length <= 104
// s consists of only English letters and spaces ' '.

// Test case:
// "Hello World"
// " "
// "This is another    test"
// "a   "
// Output:
//Output
// 5 0 4 1

// https://leetcode.com/problems/length-of-last-word/submissions/

// Runtime: 4 ms, faster than 65.47% of C++ online submissions for Length of Last Word.
// Memory Usage: 6.5 MB, less than 82.90% of C++ online submissions for Length of Last Word.

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        auto len = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if (*it == ' ')
            {
                if (len)
                {
                    break;
                }
                //Skip suffix strings
            }
            else
            {
                ++len;
            }
        }
        return len;
    }
};
