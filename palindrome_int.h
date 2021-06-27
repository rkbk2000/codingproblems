// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

// Example 1:

// Input: x = 121
// Output: true
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Example 4:

// Input: x = -101
// Output: false

// Constraints:

// -2^31 <= x <= 2^31 - 1

// Runtime: 8 ms, faster than 76.06% of C++ online submissions for Palindrome Number.
// Memory Usage: 6 MB, less than 26.44% of C++ online submissions for Palindrome Number.

// Solution 1: by converting to a string
class Solution
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0)
        {
            // Negative number
            return false;
        }

        if (x < 9)
        {
            // Single digit number
            return true;
        }

        auto s = to_string(x);
        int mid = s.size() / 2;
        auto l = mid - 1, r = mid;
        if (s.size() & 0x01)
        {
            // Skip the digit in odd place
            ++r;
        }

        for (; l >= 0; l--, r++)
        {
            if (s[l] != s[r])
            {
                return false;
            }
        }
        return true;
    }
};

// Runtime: 8 ms, faster than 76.06% of C++ online submissions for Palindrome Number.
// Memory Usage: 5.8 MB, less than 89.28% of C++ online submissions for Palindrome Number.

// Improved version
class Solution1
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0)
        {
            // Negative number
            return false;
        }

        if (x < 9)
        {
            // Single digit number
            return true;
        }

        const int MAX_LEN = 10;

        // Max size of int32 cannot croos 10 digits
        array<uint8_t, MAX_LEN> digits{0};

        auto size = 0;
        while (x > 0)
        {
            digits[size++] = x % 10;
            x /= 10;
        }

        int mid = size / 2;
        auto l = mid - 1, r = mid;
        if (size & 0x01)
        {
            // Skip the digit in odd place
            ++r;
        }

        for (; l >= 0; l--, r++)
        {
            if (digits[l] != digits[r])
            {
                return false;
            }
        }

        return true;
    }
};