// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to make it fancy.

// Return the final string after the deletion. It can be shown that the answer will always be unique.

// Example 1:

// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation:
// Remove an 'e' from the first group of 'e's to create "leetcode".
// No three consecutive characters are equal, so return "leetcode".
// Example 2:

// Input: s = "aaabaaaa"
// Output: "aabaa"
// Explanation:
// Remove an 'a' from the first group of 'a's to create "aabaaaa".
// Remove two 'a's from the second group of 'a's to create "aabaa".
// No three consecutive characters are equal, so return "aabaa".
// Example 3:

// Input: s = "aab"
// Output: "aab"
// Explanation: No three consecutive characters are equal, so return "aab".

// Constraints:

// 1 <= s.length <= 10^5
// s consists only of lowercase English letters.

// Hints:
// What's the optimal way to delete characters if three or more consecutive characters are equal?
// If three or more consecutive characters are equal, keep two of them and delete the rest.

// 08/07/2021 20:42	Accepted	248 ms	41.2 MB	cpp

class Solution
{
public:
    string makeFancyString(string s)
    {
        if (s.size() < 3)
        {
            return s;
        }

        int i = 0;
        string result;

        while (i < s.size())
        {
            // 3 are equal
            if (i >= 2 && (s[i] == s[i - 1] && s[i - 1] == s[i - 2]))
            {
                while (s[i] == s[i - 1] && i < s.size())
                {
                    i++;
                }
                // s.erase(start,i-start);
                // i = start;
            }
            else
            {
                result.push_back(s[i++]);
            }
        }
        return result;
    }
};

// Another solution
// Runtime: 140 ms, faster than 16.67% of C++ online submissions for Delete Characters to Make Fancy String.
// Memory Usage: 40.2 MB, less than 16.67% of C++ online submissions for Delete Characters to Make Fancy String.
class Solution140
{
public:
    string makeFancyString(string s)
    {

        string result(s);
        int len = 0;
        for (auto c : s)
        {
            if (len < 2 || result[len - 1] != c || result[len - 2] != c)
            {
                result[len++] = c;
            }
        }
        result.resize(len);
        return result;
    }
};
