// Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Example 2:

// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Example 3:

// Input: digits = [0]
// Output: [1]

// Constraints:

// 1 <= digits.length <= 100
// 0 <= digits[i] <= 9
// https://leetcode.com/problems/plus-one
// Runtime: 4 ms, faster than 48.51% of C++ online submissions for Plus One.
// Memory Usage: 8.7 MB, less than 56.23% of C++ online submissions for Plus One.
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int size = digits.size();
        int carry = 0;

        digits[size - 1] += 1;
        if (digits[size - 1] > 9)
        {
            digits[size - 1] -= 10;
            carry = 1;
        }

        for (auto i = size - 2; i >= 0; --i)
        {
            auto s = digits[i] + carry;
            if (s > 9)
            {
                s -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            digits[i] = s;
        }
        if (carry)
        {
            auto it = digits.begin();
            digits.insert(it, 1);
        }
        return digits;
    }
};