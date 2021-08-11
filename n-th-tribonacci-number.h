// https://leetcode.com/problems/n-th-tribonacci-number/

// The Tribonacci sequence Tn is defined as follows:

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// Example 2:

// Input: n = 25
// Output: 1389537

// Constraints:

// 0 <= n <= 37
// The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

// Make an array F of length 38, and set F[0] = 0, F[1] = F[2] = 1.
// Now write a loop where you set F[n+3] = F[n] + F[n+1] + F[n+2], and return F[n].

// Testcase:
// 4
// 10
// 30

// Output:
// 4
// 149
// 29249425

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 5.9 MB, less than 46.18% of C++ online submissions for N-th Tribonacci Number.

class Solution
{
public:
    int tribonacci(int n)
    {
        int t0{0}, t1{1}, t2{1};

        if (n == 0)
            return t0;
        if (n <= 2)
            return t2;

        for (int i = 3; i <= n; i++)
        {
            auto sum = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = sum;
        }
        return t2;
    }
};

// Recursive solution gets a TLE