// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

// Runtime: 16 ms, faster than 30.39% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.2 MB, less than 93.94% of C++ online submissions for Valid Anagram.

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

// Runtime: 4 ms, faster than 99.15% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.4 MB, less than 7.00% of C++ online submissions for Valid Anagram.
class SolutionFreq2
{
public:
    bool isAnagram(string s, string t)
    {
        // Using frequency of letters
        vector<int> freq1(26, 0), freq2(26, 0);

        for (auto c : s)
            freq1[c - 'a']++;
        for (auto c : t)
            freq2[c - 'a']++;

        return freq1 == freq2;
    }
};

// Runtime: 4 ms, faster than 99.15% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.2 MB, less than 93.94% of C++ online submissions for Valid Anagram.
class SolutionOneFreq
{
public:
    bool isAnagram(string s, string t)
    {
        // Using frequency of letters
        vector<int> freq(26, 0);

        for (auto c : s)
            freq[c - 'a']++;
        for (auto c : t)
            freq[c - 'a']--;
        auto it = std::find_if(freq.begin(), freq.end(), [](int n)
                               { return n != 0; });

        return (it == freq.end());
    }
};