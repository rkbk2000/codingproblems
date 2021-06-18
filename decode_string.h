
// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Testcases:
// "3[a]2[bc]"
// "300[a]"
// "abc3[ab]"
// "abc"
// "3[a2[c]]"
// "2[abc]3[cd]ef"

// Output:
// "aaabcbc"
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
// "abcababab"
// "abc"
// "accaccacc"
// "abcabccdcdcdef"

// https://leetcode.com/problems/decode-string/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
// Memory Usage: 6.5 MB, less than 71.30% of C++ online submissions for Decode String.

class Solution
{
    enum chartype
    {
        alpha,
        digit,
        sqs, // SQ bracket start
        sqe  // SQ bracket end

    };

public:
    string decodeString(string s)
    {
        stack<string> echars;
        // 1. Group continuous alphabets or digits together
        // 2. Push the grouped string to stack
        // 3. As soon as you find a [ put it to stack
        // As soon as you encounter a ], pop from stack until you find a [ and previous string
        // Repeat the current string n times as mentioned by previous number
        // Continue
        string cur{};
        chartype state = sqs;
        for (auto iter = s.begin(); iter != s.end(); ++iter)
        {
            if (isdigit(*iter))
            {
                if (state == alpha)
                {
                    // Previous state was alphabet
                    echars.push(cur);
                    cur = *iter;
                    state = digit;
                }
                else
                {
                    // Must be a digit
                    cur += *iter;
                }
            }
            else if (isalpha(*iter))
            {
                // IS an alphabetical character
                cur += *iter;
                state = alpha;
            }
            else if (*iter == '[')
            {
                // Time to insert the number
                echars.push(cur);
                cur = "";
            }
            else if (*iter == ']')
            {
                // Time to insert modified string
                auto cnt = std::stol(echars.top());
                echars.pop();
                string out;
                out.reserve((cur.size() * cnt) + 1);
                for (auto i = 0; i < cnt; ++i)
                {
                    out += cur;
                }
                if (!echars.empty() && isalpha(echars.top()[0]))
                {
                    // If we found a string previously add it
                    out = echars.top() + out;
                    echars.pop();
                }
                cur = out;
            }
        }

        string result{};
        while (!echars.empty())
        {
            auto sub = echars.top();
            echars.pop();
            sub += result;
            result = sub;
        }

        // Scenario of no []
        if (!cur.empty())
        {
            cur = cur + result;
            result = cur;
        }
        return result;
    }
};