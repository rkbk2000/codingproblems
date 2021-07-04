// Runtime: 4 ms, faster than 55.40% of C++ online submissions for Substrings of Size Three with Distinct Characters.
// Memory Usage: 8.3 MB, less than 5.63% of C++ online submissions for Substrings of Size Three with Distinct Characters.
// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/submissions/
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        auto sz = s.size();
        auto cnt = 0;
        if (sz < 3)
        {
            return cnt;
        }
        set<char> chars;
        for (int i = 0; i < sz - 2; i++)
        {
            chars.emplace(s[i]);
            chars.emplace(s[i + 1]);
            chars.emplace(s[i + 2]);
            if (chars.size() == 3)
            {
                ++cnt;
            }
            chars.clear();
        }
        return cnt;
    }
};

// Improved version
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Substrings of Size Three with Distinct Characters.
// Memory Usage: 6.1 MB, less than 72.49% of C++ online submissions for Substrings of Size Three with Distinct Characters.
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        auto cnt = 0;
        for (int i = 2; i < s.size(); i++)
        {
            if ((s[i] != s[i - 1]) && (s[i - 1] != s[i - 2]) && (s[i] != s[i - 2]))
            {
                ++cnt;
            }
        }
        return cnt;
    }
};