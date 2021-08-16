// Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: patterns = ["a","abc","bc","d"], word = "abc"
// Output: 3
// Explanation:
// - "a" appears as a substring in "abc".
// - "abc" appears as a substring in "abc".
// - "bc" appears as a substring in "abc".
// - "d" does not appear as a substring in "abc".
// 3 of the strings in patterns appear as a substring in word.
// Example 2:

// Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
// Output: 2
// Explanation:
// - "a" appears as a substring in "aaaaabbbbb".
// - "b" appears as a substring in "aaaaabbbbb".
// - "c" does not appear as a substring in "aaaaabbbbb".
// 2 of the strings in patterns appear as a substring in word.
// Example 3:

// Input: patterns = ["a","a","a"], word = "ab"
// Output: 3
// Explanation: Each of the patterns appears as a substring in word "ab".

// Constraints:

// 1 <= patterns.length <= 100
// 1 <= patterns[i].length <= 100
// 1 <= word.length <= 100
// patterns[i] and word consist of lowercase English letters.

// Hints:
// Deal with each of the patterns individually.
// Use the built-in function in the language you are using to find if the pattern exists as a substring in word.

// Runtime: 4 ms, faster than 80.00% of C++ online submissions for Number of Strings That Appear as Substrings in Word.
// Memory Usage: 8.7 MB, less than 60.00% of C++ online submissions for Number of Strings That Appear as Substrings in Word.

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        auto result = 0;
        for (auto &pattern : patterns)
        {
            if (word.find(pattern) != string::npos)
            {
                result++;
            }
        }
        return result;
    }
};