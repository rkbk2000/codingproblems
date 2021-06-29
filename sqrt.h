// Given a non-negative integer x, compute and return the square root of x.

// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

// Example 1:

// Input: x = 4
// Output: 2
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

// Constraints:

// 0 <= x <= 2^31 - 1

// Test case:
// 4
// 23
// 99
// 2147483647
// 1

// Result
// 2
// 4
// 9
// 46340
// 1

// Runtime: 184 ms, faster than 5.91% of C++ online submissions for Sqrt(x).
// Memory Usage: 222.5 MB, less than 20.53% of C++ online submissions for Sqrt(x).

class Solution
{
public:
    int mySqrt(int x)
    {
        // sqrt of Max possible 32 bit number = 46340
        const int MAX_SQRT = 46340;
        vector<int> squares(MAX_SQRT + 1);
        for (auto i = 1; i <= MAX_SQRT; ++i)
        {
            squares[i] = i * i;
        }

        // Find the index of approximate number
        auto lb = lower_bound(squares.begin(), squares.end(), x);

        if (lb == squares.end())
        {
            return MAX_SQRT;
        }
        auto approx = lb - squares.begin();
        return (squares[approx] == x) ? approx : approx - 1;
    }
};

// More efficient solution
class SolutionBinSearch
{
public:
    int mySqrt(int x)
    {
        const int MAX_SQRT = 46340;
        auto r = x <= MAX_SQRT ? x : MAX_SQRT,
             l = 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int y = x / mid;

            if (mid == y)
            {
                // Perfect sqrt
                return mid;
            }

            if (mid < y)
            {
                // Answer between mid and y
                l = mid + 1;
            }
            else
            {
                // Answer between y and mid-1
                r = mid - 1;
            }
        }

        return r;
    }
};