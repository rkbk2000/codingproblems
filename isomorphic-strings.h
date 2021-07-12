// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true

// Constraints:

// 1 <= s.length <= 5 * 10^4
// t.length == s.length
// s and t consist of any valid ascii character.

// https://leetcode.com/problems/isomorphic-strings/submissions/

// Testcase:
// "egg"
// "add"
// "foo"
// "bar"
// "foo"
// "baa"
// "paper"
// "title"
// "rama"
// "jana"
// "rama"
// "jane"
// "a"
// "b"
// "badc"
// "baba"
// "abad"
// "babe"
// "abad"
// "bcbe"

// // Output:
// true
// false
// true
// true
// true
// false
// true
// false
// true
// true

// Runtime: 8 ms, faster than 64.89% of C++ online submissions for Isomorphic Strings.
// Memory Usage: 7.1 MB, less than 39.61% of C++ online submissions for Isomorphic Strings.
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // mapping from s to t
        unordered_map<char, char> st;

        // Set of mapped characters
        unordered_set<char> mapped;

        for (auto i = 0; i < s.size(); i++)
        {
            auto sit = st.find(s[i]);
            if (sit != st.end())
            {
                if (sit->second != t[i])
                {
                    return false;
                }
            }
            else
            {
                // t[i] should not have been already mapped
                auto mit = mapped.find(t[i]);
                if (mit != mapped.end())
                {
                    return false;
                }
                mapped.emplace(t[i]);
            }

            st[s[i]] = t[i];
        }
        return true;
    }
};

// Another implementation using hash map and hash set
// Runtime: 24 ms, faster than 5.94% of C++ online submissions for Isomorphic Strings.
// Memory Usage: 9.7 MB, less than 5.02% of C++ online submissions for Isomorphic Strings.
class SolutionH
{
public:
    bool isIsomorphic(string s, string t)
    {
        // mapping from s to t
        unordered_map<char, char> st;

        // Set of mapped characters
        unordered_set<char> mapped;

        for (auto i = 0; i < s.size(); i++)
        {
            auto sti = st.emplace(s[i], t[i]);

            if (!sti.second)
            {
                // s is already mapped, check if it is same as t[i]
                if (sti.first->second != t[i])
                {
                    return false;
                }
            }
            else
            {
                // t[i] should not have been already mapped
                auto mpi = mapped.emplace(t[i]);
                if (!mpi.second)
                {
                    // Element already mapped
                    return false;
                }
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/isomorphic-strings/solution/

// Is there any string transformation we can apply to both the strings such that to check for isomorphism, we simply check if their modified versions are exactly the same?

// One can come up with various such transformations giving us different variations of this solution. We will stick with one such transformations for the official solution.

// For each character in the given string, we replace it with the index of that character's first occurence in the string.