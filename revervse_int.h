// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit
// integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
// Example 4:

// Input: x = 0
// Output: 0

// Constraints:

// -231 <= x <= 231 - 1

// https://leetcode.com/problems/reverse-integer/submissions/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
// Memory Usage: 5.8 MB, less than 72.93% of C++ online submissions for Reverse Integer.

class Solution
{
public:
    int reverse(int x)
    {
        // INT_MAX  2147483647
        // INT_MIN -2147483648
        auto negative = false;

        if (x < 0)
        {
            negative = true;
            x = abs(x);
        }

        auto n = 0, ans = 0, first = 0;
        while (x > 0)
        {
            auto dig = x % 10;
            x /= 10;

            if (n == 0)
            {
                first = dig;
            }

            if (n == 9)
            {
                //  overflow?
                if (first > 2)
                {
                    ans = 0;
                    break;
                }
                else if (ans > 214748364)
                {
                    ans = 0;
                    break;
                }
            }
            ans = ans * 10 + dig;
            ++n;
        }

        if (negative)
        {
            ans *= -1;
        }
        return ans;
    }
};