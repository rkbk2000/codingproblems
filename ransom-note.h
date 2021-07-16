// Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.
// Runtime: 12 ms, faster than 90.03% of C++ online submissions for Ransom Note.
// Memory Usage: 8.8 MB, less than 66.93% of C++ online submissions for Ransom Note.

// https: //leetcode.com/problems/ransom-note/submissions/

// test case:
// "a"
// "b"
// "aa"
// "ab"
// "aa"
// "aab"

// Output:
// false
// false
// true

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> rn(26, 0), mg(26, 0);

        for (auto i = 0; i < ransomNote.size(); i++)
        {
            rn[ransomNote[i] - 'a']++;
        }

        for (auto i = 0; i < magazine.size(); i++)
        {
            mg[magazine[i] - 'a']++;
        }

        for (auto i = 0; i < 26; i++)
        {
            if (rn[i] > mg[i])
            {
                return false;
            }
        }

        auto it = find_first_of(rn.begin(), rn.end(), mg.begin(), mg.end(), [](int l, int r)
                                { return l > r; });
        return it != rn.end();
    }
};