// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.

// Follow up: Could you find an algorithm that runs in O(m + n) time?

// Hints:
// Use two pointers to create a window of letters in S, which would have all the characters from T.
// Since you have to find the minimum window in S which has all the characters from T, you need to expand and contract the window using the two pointers and keep checking the window for all the characters. This approach is also called Sliding Window Approach.

// L ------------------------ R , Suppose this is the window that contains all characters of T

//         L----------------- R , this is the contracted window. We found a smaller window that still contains all the characters in T

// When the window is no longer valid, start expanding again using the right pointer.

// Submissions:
// 08/16/2021 11:51	Accepted	8 ms	7.8 MB	cpp

class Solution
{
public:
        string minWindow(string s, string t)
        {

                // Frequency of different characters in string t
                vector<int> freq(128, 0);
                for (auto c : t)
                {
                        freq[c]++;
                }

                int tlen = t.size();
                int l{0}, r{0}, minstart{0}, minlen = INT_MAX;

                int sz = s.size();

                while (r < sz)
                {
                        // Decrease the frequency of current character in search string
                        if (--freq[s[r++]] >= 0)
                                --tlen;

                        // If we have found all characters, try to reduce the window size
                        while (tlen == 0)
                        {
                                if (r - l < minlen)
                                {
                                        minlen = r - l;
                                        minstart = l;
                                }

                                // Try to reduce the window size
                                if (++freq[s[l++]] > 0)
                                        ++tlen;
                        }
                }
                return minlen < INT_MAX ? s.substr(minstart, minlen) : "";
        }
};