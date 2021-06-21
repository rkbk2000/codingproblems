// You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

// The ith item is said to match the rule if one of the following is true:

// ruleKey == "type" and ruleValue == typei.
// ruleKey == "color" and ruleValue == colori.
// ruleKey == "name" and ruleValue == namei.
// Return the number of items that match the given rule.

// Runtime: 60 ms, faster than 97.77% of C++ online submissions for Count Items Matching a Rule.
// Memory Usage: 31 MB, less than 38.12% of C++ online submissions for Count Items Matching a Rule.

// 06/21/2021 18:23	Accepted	60 ms	31 MB	cpp
// 06 / 21 / 2021 18 : 19 Accepted 68 ms 30.9 MB cpp

// https://leetcode.com/problems/count-items-matching-a-rule/
class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        auto idxToCheck = 0;

        if (ruleKey == "color")
        {
            idxToCheck = 1;
        }
        else if (ruleKey == "name")
        {
            idxToCheck = 2;
        }

        auto matches = 0;
        // std::all_of(items.begin(),items.end(), [&](const vector<string>& vals){ if (vals[idxToCheck] == ruleValue){ ++matches;} return true;});

        for (auto &iter : items)
        {
            if (iter[idxToCheck] == ruleValue)
            {
                ++matches;
            }
        }
        return matches;
    }
};