// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.
//https://leetcode.com/problems/longest-common-prefix/submissions/

// Test cases:
// ["flower","flow","flight"]
// ["dog","racecar","car"]
// ["aa"]
// ["a"]
// ["aa","aa"]

//Output:
// "fl"
// ""
// "aa"
// "a"
// "aa"
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.1 MB, less than 75.64% of C++ online submissions for Longest Common Prefix.

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // Sorth the arrays
        std::sort(strs.begin(), strs.end());

        auto ns = strs.size();
        auto len = 0;
        // check Each character of first string with the last
        for (auto i = 0; i < strs[0].size(); i++)
        {
            if (strs[0][i] != strs[ns - 1][i])
            {
                len = i;
                break;
            }
            ++len;
        }
        return string(strs[0], 0, len);
    }
};