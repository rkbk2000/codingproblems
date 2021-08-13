// https://leetcode.com/problems/longest-palindromic-substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

// Hints:
// How can we reuse a previously computed palindrome to compute a larger palindrome?
// If “aba” is a palindrome, is “xabax” a palindrome? Similarly is “xabay” a palindrome?
// Complexity based hint:
// If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.

// Runtime: 43 ms, faster than 68.98% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 7.1 MB, less than 83.34% of C++ online submissions for Longest Palindromic Substring.

// Approach 1: Expand around center
// In fact, we could solve it in O(n^2) time using only constant space.

// We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n−1 such centers.

// You might be asking why there are 2n−1 but not nn centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.

// Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).

// Space complexity : O(1)O(1).
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto l1 = expandAroundCenter(s, i, i);
            auto l2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(l1, l2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(const string &s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
};

// Approach 2: Brute Force
// The brute force solution is to pick all possible starting and ending positions for a substring, and verify if it is a palindrome.

// Complexity Analysis

// Time complexity : O(n^3). if n is the length, there are (n(n-1)/2)  such substrings (excluding the trivial solution where a character
// itself is a palindrome). Since verifying each substring takes O(n) time, the run time complexity is O(n^3)
// Space complexity : O(1)
// Runtime: 1816 ms, faster than 5.01% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 24.5 MB, less than 45.20% of C++ online submissions for Longest Palindromic Substring.

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();        
        if (sz < 2 ) return s;
        
        int mxlen = INT_MIN;
        string result{};
        
        for (int i = 1; i < sz; i++) {
            for (int j=0; j<=i; j++) {
                if (isPalindrome(s, j, i)) {
                    int l = i-j+1;
                    if (l > mxlen) {
                        result = s.substr(j, l);
                        mxlen = l;
                    }
                }
            }
        }
        return result;
    }
    
    bool isPalindrome(const string&s, int l, int r) {        
        int end = l + (r-l+1)/2;
        while (l < end) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }        
        return true;
    }
};

// Approach 3: Dynamic Programming
// To improve over the brute force solution, we first observe how we can avoid unnecessary re-computation while validating palindromes. Consider the case "ababa". If we already knew that "bab" is a palindrome, it is obvious that "ababa" must be a palindrome since the two left and right end letters are the same.

// We define P(i,j) as following:

// P(i,j) = true, if the substring Si...Sj  is a palindrome
//          false, otherwise
// ​

// P(i, j) = ( P(i+1, j-1) and S_i == S_j )

// The base cases are:
// P(i, i) = true
// P(i, i+1) = ( S_i == S_{i+1} )

// This yields a straight forward DP solution, which we first initialize the one and two letters palindromes, and work our way up finding all three letters palindromes, and so on...

// Complexity Analysis

// Time complexity : O(n^2). This gives us a runtime complexity of O(n^2).
// Space complexity : O(n^2). It uses O(n^2) space to store the table.