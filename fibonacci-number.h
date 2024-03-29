// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

// Constraints:

// 0 <= n <= 30

// Testcase:
// 0
// 2
// 5
// 30

// Output:
// 0
// 1
// 5
// 832040

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 5.9 MB, less than 38.95% of C++ online submissions for Fibonacci Number.

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        int f0 = 0, f1 = 1;
        for (int i = 1; i < n; i++)
        {
            f1 = f0 + f1;
            f0 = f1 - f0;
        }
        return f1;
    }
};

// Using recursion
class SolutionRecursive
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};