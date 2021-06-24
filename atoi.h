// Implment atoi

// Test cases:
// "1"
// "12"
// "1234567890"
// "-1"
// "-12"
// "-1234567890"
// "12 34"
// "-12 -34"
// "-0000000000000042"
// "+0000000000000042"
// "   -42"
// "+43"
// "+043"
// "2147483647"
// "+2147483647"
// "-2147483648"
// "-3147483648"
// "-1147483648"
// "21474836479"
// "2147483647a"
// "-21474836488"
// "-2147483648a"
// "   -42"
// "4193 with words"
// "words and 987"
// "-91283472332"
// "21474836460"
// "-21474836460"
// "2147483800"
// "-2157483648"
// "20000000000000000000"

// Output:
// 1
// 12
// 1234567890
// -1
// -12
// -1234567890
// 12
// -12
// -42
// 42
// -42
// 43
// 43
// 2147483647
// 2147483647
// -2147483648
// -2147483648
// -1147483648
// 2147483647
// 2147483647
// -2147483648
// -2147483648
// -42
// 4193
// 0
// -2147483648
// 2147483647
// -2147483648
// 2147483647
// -2147483648
// 2147483647

// https : //leetcode.com/problems/string-to-integer-atoi/submissions/
// Runtime: 4 ms, faster than 62.77% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 7.3 MB, less than 6.63% of C++ online submissions for String to Integer (atoi).

class Solution
{
public:
    int myAtoi(string s)
    {
        // INT_MAX  2147483647
        // INT_MIN -2147483648
        auto idx = 0;
        // Remove spaces if any
        while (!s.empty() && s[idx] == ' ')
        {
            ++idx;
        }

        // No more characters to process
        if (s.empty())
        {
            return 0;
        }

        // Check if negative or positive
        auto negative = false;
        switch (s[idx])
        {
        case '-':
            negative = true;
            ++idx;
            break;
        case '+':
            ++idx;
            break;
        }

        // Do not read more than 11 consecutive digits - because values will go out of range
        auto read_max = 11, start = idx;
        // Read digits until end of string or read_max or not a digit
        auto skipzero = true;
        while (!s.empty() && isdigit(s[idx]))
        {
            if (skipzero && s[idx] == '0')
            {
                // Skip leading zeros
                ++start;
                ++idx;
                continue;
            }
            ++idx;
            skipzero = false;
            if (read_max == (idx - start + 1))
            {
                // Out of bounds
                break;
            }
        }
        auto nstr = string(s, start, idx - start);

        if (nstr.empty())
        {
            return 0;
        }

        auto ans = 0;
        // If length is 10, check the first character and return INT_MAX/MIN
        if (nstr.size() == 10)
        {
            if (((nstr[0] - '0') > 2) || ((s.size() > idx) && isdigit(s[idx])))
            {
                // First digit > 2
                ans = negative ? INT_MIN : INT_MAX;
            }
        }
        else if (nstr.size() == 11)
        {
            ans = negative ? INT_MIN : INT_MAX;
        }

        if (ans == 0)
        {
            // Check the boundary conditions
            if (nstr.size() == 10)
            {
                if (nstr[0] == '2')
                {
                    if (negative && ((nstr[9] - '0') > 7))
                    {
                        ans = INT_MIN;
                    }
                    else if (!negative && ((nstr[9] - '0') > 7))
                    {
                        ans = INT_MAX;
                    }
                }
            }

            if (ans == 0)
            {
                int64_t temp = 0;
                // Now calculate actual value
                for (auto int i = nstr.size() - 1, j = 0; i >= 0; --i, ++j)
                {
                    temp += pow(10, i) * (nstr[j] - '0');
                }
                if (negative)
                {
                    if (temp > ((int64_t)INT_MAX + 1))
                    {
                        ans = INT_MIN;
                    }
                    else
                    {
                        ans = temp * (-1);
                    }
                }
                else
                {
                    if (temp > INT_MAX)
                    {
                        ans = INT_MAX;
                    }
                    else
                    {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};

// Simpler version
// Runtime: 4 ms, faster than 62.77% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 7.6 MB, less than 6.63% of C++ online submissions for String to Integer (atoi).
class Solution1
{
public:
    int myAtoi(string s)
    {
        auto ans = 0;

        auto skipspaces = [](string &str)
        {
            auto iter = str.begin();
            while (iter != str.end())
            {
                if (*iter != ' ')
                {
                    return;
                }
                iter = str.erase(iter);
            }
        };

        try
        {
            ans = stoi(s);
        }
        catch (std::out_of_range &exp)
        {
            skipspaces(s);
            if (s[0] == '-')
            {
                ans = INT_MIN;
            }
            else
            {
                ans = INT_MAX;
            }
        }
        catch (std::invalid_argument &exp)
        {
            // called when the string starts with alphabets.
            // Do nothing, default value is zero
        }
        return ans;
    }
};