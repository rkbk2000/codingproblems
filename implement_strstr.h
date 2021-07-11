// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Example 3:

// Input: haystack = "", needle = ""
// Output: 0

// Constraints:

// 0 <= haystack.length, needle.length <= 5 * 104
// haystack and needle consist of only lower-case English characters.
// https://leetcode.com/problems/implement-strstr/submissions/

// Runtime: 20 ms, faster than 22.37% of C++ online submissions for Implement strStr().
// Memory Usage: 7.1 MB, less than 18.10% of C++ online submissions for Implement strStr().

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        auto ans = haystack.find(needle);
        return (ans == std::string::npos) ? -1 : ans;
    }
};

// Runtime: 560 ms, faster than 16.81% of C++ online submissions for Implement strStr().
// Memory Usage: 7.2 MB, less than 8.55% of C++ online submissions for Implement strStr().

// Another handcoded implmenetation
class SolutionHC
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        int hs = haystack.size();
        int ns = needle.size();

        for (auto i = 0; i < hs - ns + 1; i++)
        {
            if (haystack[i] == needle[0])
            {
                auto j = 1;
                auto pos = i, cur = i + 1;
                while (cur < hs && j < ns && haystack[cur] == needle[j])
                {
                    cur++;
                    j++;
                }
                if (j == ns)
                {
                    return pos;
                }
            }
        }
        return -1;
    }
};