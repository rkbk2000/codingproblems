// order and str are strings composed of lowercase letters. In order, no letter occurs more than once.

// order was sorted in some custom order previously. We want to permute the characters of str so that they match the order that order was sorted. More specifically, if x occurs before y in order, then x should occur before y in the returned string.

// Return any permutation of str (as a string) that satisfies this property.

// Example:
// Input:
// order = "cba"
// str = "abcd"
// Output: "cbad"
// Explanation:
// "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

// Note:

// order has length at most 26, and no character is repeated in order.
// str has length at most 200.
// order and str consist of lowercase letters only.

// https://leetcode.com/problems/custom-sort-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Custom Sort String.
// Memory Usage: 6.1 MB, less than 93.89% of C++ online submissions for Custom Sort String.

// Testcase:
// "cba"
// "abcd"

// Result:
// "cbad"

class Solution
{
public:
    string customSortString(string order, string str)
    {
        vector<int> dict(26, INT_MAX);
        for (auto i = 0; i < order.size(); i++)
        {
            dict[order[i] - 'a'] = i;
        }

        std::sort(str.begin(), str.end(), [&](char i, char j)
                  { return dict[i - 'a'] < dict[j - 'a']; });
        return str;
    }
};

// Handcoded solution
class SolutionHC
{
public:
    string customSortString(string order, string str)
    {

        // Map of characters vs their indexes
        map<char, int> orderpos;

        for (auto i = 0; i < order.size(); i++)
        {
            orderpos[order[i]] = i;
        }

        // Count of characters
        vector<int> counts(26, 0);

        string suffix{};
        for (auto i = 0; i < str.size(); i++)
        {
            auto it = orderpos.find(str[i]);
            if (it != orderpos.end())
            {
                counts[it->second]++;
            }
            else
            {
                suffix += str[i];
            }
        }

        string prefix{};
        for (auto i = 0; i < 26; i++)
        {
            if (counts[i])
            {
                prefix.append(counts[i], order[i]);
            }
            else
            {
                break;
            }
        }
        return prefix + suffix;
    }
};