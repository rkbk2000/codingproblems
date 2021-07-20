// Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

// You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

// Return the reformatted string or return an empty string if it is impossible to reformat the string.

// Example 1:

// Input: s = "a0b1c2"
// Output: "0a1b2c"
// Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
// Example 2:

// Input: s = "leetcode"
// Output: ""
// Explanation: "leetcode" has only characters so we cannot separate them by digits.
// Example 3:

// Input: s = "1229857369"
// Output: ""
// Explanation: "1229857369" has only digits so we cannot separate them by characters.
// Example 4:

// Input: s = "covid2019"
// Output: "c2o0v1i9d"
// Example 5:

// Input: s = "ab123"
// Output: "1a2b3"

// Constraints:

// 1 <= s.length <= 500
// s consists of only lowercase English letters and/or digits.

// https://leetcode.com/problems/reformat-the-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reformat The String.
// Memory Usage: 7.8 MB, less than 21.73% of C++ online submissions for Reformat The String.

class Solution
{
public:
    string reformat(string s)
    {
        vector<char> digits, chars;
        for (auto c : s)
        {
            if (isdigit(c))
            {
                digits.emplace_back(c);
            }
            else
            {
                chars.emplace_back(c);
            }
        }
        string ans{};
        int s1 = digits.size(), s2 = chars.size();
        auto &l = digits, &r = chars;

        if (s1 < s2)
        {
            std::swap(l, r);
            std::swap(s1, s2);
        }

        if (s1 - s2 > 1)
        {
            // Not possible
            return ans;
        }

        for (auto i = 0; i < s2; i++)
        {
            ans += l[i];
            ans += r[i];
        }
        if (s1 != s2)
        {
            ans += l[s1 - 1];
        }
        return ans;
    }
};