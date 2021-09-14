// https://leetcode.com/problems/reverse-only-letters/

// 917. Reverse Only Letters
// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.

// Example 1:

// Input: s = "ab-cd"
// Output: "dc-ba"
// Example 2:

// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:

// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"

// Constraints:

// 1 <= s.length <= 100
// s consists of characters with ASCII values in the range [33, 122].
// s does not contain '\"' or '\\'.

// Hint:
// This problem is exactly like reversing a normal string except that there are certain characters that we have to simply skip. That should be easy enough to do if you know how to reverse a string using the two-pointer approach.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.
// Memory Usage: 6.1 MB, less than 21.68% of C++ online submissions for Reverse Only Letters.

// Two pointer approach
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int sz = s.size();
        int l = 0, r = sz - 1;

        while (l < r)
        {
            while (l < sz && !isalpha(s[l]))
                l++;
            while (r >= 0 && !isalpha(s[r]))
                r--;

            if (l < r)
            {
                std::swap(s[l], s[r]);
            }
            l++;
            r--;
        }
        return s;
    }
};

// Using a stack
class SolutionStack
{
public:
    string reverseOnlyLetters(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (isalpha(c))
            {
                st.push(c);
            }
        }

        string result;
        for (auto c : s)
        {
            if (isalpha(c))
            {
                result += st.top();
                st.pop();
            }
            else
            {
                result += c;
            }
        }

        return result;
    }
};