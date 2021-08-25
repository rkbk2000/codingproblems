// https://leetcode.com/problems/valid-perfect-square/

// 367. Valid Perfect Square
// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Follow up: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: num = 16
// Output: true
// Example 2:

// Input: num = 14
// Output: false

// Constraints:

// 1 <= num <= 2^31 - 1

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
// Memory Usage: 5.9 MB, less than 63.52% of C++ online submissions for Valid Perfect Square.

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int sq = sqrt(num);
        for (int i = 1;; i++)
        {
            int64_t res = (int64_t)i * i;
            if ((int)res == num)
            {
                return true;
            }
            else if (res > num)
            {
                break;
            }
        }
        return false;
    }
};