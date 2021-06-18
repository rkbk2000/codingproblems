// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

// Test case:
// "bank"
// "kanb"
// "attack"
// "defend"
// "kelb"
// "kelb"
// "abcd"
// "dcba"

// Output:
// true
// false
// true
// false

// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
// Memory Usage: 6.1 MB, less than 76.44% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        auto nonEqPositions = 0;
        auto rc = true;
        char out1[2], out2[2];
        auto len = s1.size();
        for (auto i = 0; i < len; ++i)
        {
            if (s1[i] == s2[i])
            {
                continue;
            }
            ++nonEqPositions;
            if (nonEqPositions > 2)
            {
                // one swap not possible
                rc = false;
                break;
            }
            else
            {
                out1[nonEqPositions - 1] = s1[i];
                out2[nonEqPositions - 1] = s2[i];
            }
        }

        if (rc && nonEqPositions)
        {
            if ((out1[0] == out2[0]) && (out1[1] == out2[1]) ||
                (out1[1] == out2[0]) && (out1[0] == out2[1]))
            {
                rc = true;
            }
            else
            {
                rc = false;
            }
        }
        return rc;
    }
};