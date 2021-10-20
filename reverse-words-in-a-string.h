// 151. Reverse Words in a String
// Medium

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
// Example 4:

// Input: s = "  Bob    Loves  Alice   "
// Output: "Alice Loves Bob"
// Example 5:

// Input: s = "Alice does not even like bob"
// Output: "bob like even not does Alice"

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 7.5 MB, less than 60.75% of C++ online submissions for Reverse Words in a String.

// Input:
// "the sky is blue"
// "  hello world  "
// "a good   example"
// "  Bob    Loves  Alice   "
// "Alice does not even like bob"

// Output:
// "blue is sky the"
// "world hello"
// "example good a"
// "Alice Loves Bob"
// "bob like even not does Alice"

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> tokens;
        int sz = s.size();
        int len = 0, prev = 0;
        auto done = false;
        while (!done)
        {
            // Skip spaces
            while (s[len] == ' ' && len < sz)
            {
                len++;
                prev++;
            }
            if (len >= sz)
                break;
            while (isalnum(s[len]) && (len < sz))
                len++;
            tokens.push(string(s, prev, len - prev));
            prev = len;
        }

        string result;
        while (!tokens.empty())
        {
            result += tokens.top() + " ";
            tokens.pop();
        }
        result.pop_back();
        return result;
    }
};