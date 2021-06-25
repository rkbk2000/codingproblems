// Reverse bits of a given 32 bits unsigned integer.

// Note:

// Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
// Follow up:

// If this function is called many times, how would you optimize it?

// Example 1:

// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
// Example 2:

// Input: n = 11111111111111111111111111111101
// Output:   3221225471 (10111111111111111111111111111111)
// Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

// Constraints:

// The input must be a binary string of length 32
// Runtime: 4 ms, faster than 54.90% of C++ online submissions for Reverse Bits.
// Memory Usage: 5.9 MB, less than 45.58% of C++ online submissions for Reverse Bits.

// Test case:
// 00000010100101000001111010011100
// 11111111111111111111111111111101
// 10000010100101000001111010011100
// 10000010100101000001111010011101
// 11111111111111111111111111111111

// Output
//    964176192 (00111001011110000010100101000000)
//   3221225471 (10111111111111111111111111111111)
//    964176193 (00111001011110000010100101000001)
//   3111659841 (10111001011110000010100101000001)
//   4294967295 (11111111111111111111111111111111)

// https://leetcode.com/problems/reverse-bits/submissions/
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        if (n == 0 || n == UINT_MAX)
        {
            return n;
        }

        uint32_t ans = 0;

        for (auto i = 31; i >= 0; i--)
        {
            if (n & 0x1)
            {
                // ans += pow(2, i);
                ans += 1 << i;
            }
            n >>= 1;
        }
        return ans;
    }
};