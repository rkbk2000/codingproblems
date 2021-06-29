// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Constraints:

// -100.0 < x < 100.0
// -2^31 <= n <= 2^31-1
// -10^4 <= xn <= 10^4

// Test cases:
// 2.00000
// 10
// 2.10000
// 3
// 2.00000
// -2
// 0.00001
// 2147483647
// 2.0
// -2147483648

// Output:
// 1024.00000
// 9.26100
// 0.25000
// 0.00000
// 0.00000

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.9 MB, less than 40.16% of C++ online submissions for Pow(x, n).

// https://leetcode.com/problems/powx-n/submissions/

class Solution
{
public:
    double myPow(double x, int n)
    {
        bool inverse = (n < 0);
        uint64_t un = abs(int64_t(n));
        double ans = 1.0;
        while (un > 0)
        {
            ans *= calcPow(x, un);
        }
        return inverse ? 1 / ans : ans;
    }

    double calcPow(double x, uint64_t &un)
    {
        auto ans = x;
        uint64_t idx = 2;
        for (; idx < un; idx *= 2)
        {
            ans *= ans;
        }
        un -= (idx / 2);
        return ans;
    }
};