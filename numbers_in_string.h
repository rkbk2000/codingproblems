// Test cases:
// "a123bc34d8ef34"
// "leet1234code234"
// "a1b01c001"
// "111"
// "a"
// "a1"
// "1a"
// "1a1a"
// "a1a1"
// "a1111"
// "0a0"
// "0"
// "0000"
// "00a000a"
// "010abc10"

// Output:
// 3
// 2
// 1
// 1
// 0
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Different Integers in a String.
// Memory Usage: 6.7 MB, less than 21.55% of C++ online submissions for Number of Different Integers in a String.

// https: //leetcode.com/problems/number-of-different-integers-in-a-string/submissions/

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        string cur{};
        set<string> numbers;
        auto flip = false;
        for (auto ch : word)
        {
            if (isalpha(ch))
            {
                if (flip)
                {
                    // Transition from digit to alphabet
                    if (cur.empty())
                    {
                        // Only zero
                        numbers.insert("0");
                    }
                    else
                    {
                        numbers.insert(cur);
                        cur = "";
                    }
                    flip = false;
                }
                continue;
            }
            flip = true;

            // It is a digit, form the substring
            if (cur.empty() && (ch == '0'))
            {
                // Skip leading zeroes
                continue;
            }
            cur += ch;
        }
        // Last number if any
        if (flip)
        {
            if (cur.empty())
            {
                numbers.insert("0");
            }
            else
            {
                numbers.insert(cur);
            }
        }
        return numbers.size();
    }
};
