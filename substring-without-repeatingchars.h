// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// Example 4:

// Input: s = ""
// Output: 0

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

// Test case:
// "abcabcbb"
// "bbbbb"
// "pwwkew"
// ""
// " "

// Output:
// 3
// 1
// 3
// 0
// 1
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Runtime: 640 ms, faster than 8.79% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 153 MB, less than 6.03% of C++ online submissions for Longest Substring Without Repeating Characters.

// Bruteforce solution
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        auto cnt = 0;
        std::unordered_set<char> chars;
        for (int i = 0; i < s.size(); i++)
        {

            for (int j = i; j < s.size(); j++)
            {
                auto it = chars.emplace(s[j]);
                if (!it.second)
                {
                    cnt = std::max(cnt, (int)chars.size());
                    chars.clear();
                    break;
                }
            }
        }
        return std::max(cnt, (int)chars.size());
    }
};