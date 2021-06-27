// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.
// Runtime: 4 ms, faster than 95.35% of C++ online submissions for Valid Palindrome.
// Memory Usage: 7.4 MB, less than 39.52% of C++ online submissions for Valid Palindrome

// https : //leetcode.com/problems/valid-palindrome/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        auto pend = std::remove_if(s.begin(), s.end(), [](const char &c)
                                   { return !isalnum(c); });
        auto len = std::distance(s.begin(), pend);
        int mid = len / 2;
        for (auto i = 0; i < mid; ++i)
        {
            if (std::tolower(s[i]) != std::tolower(s[len - i - 1]))
            {
                return false;
            }
        }
        return true;
    }
};