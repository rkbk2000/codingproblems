// https://leetcode.com/problems/count-number-of-special-subsequences/

// A sequence is special if it consists of a positive number of 0s, followed by a positive number of 1s, then a positive number of 2s.

// For example, [0,1,2] and [0,0,1,1,1,2] are special.
// In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
// Given an array nums (consisting of only integers 0, 1, and 2), return the number of different subsequences that are special. Since the answer may be very large, return it modulo 10^9 + 7.

// A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. Two subsequences are different if the set of indices chosen are different.

// Example 1:

// Input: nums = [0,1,2,2]
// Output: 3
// Explanation: The special subsequences are [0,1,2,2], [0,1,2,2], and [0,1,2,2].
// Example 2:

// Input: nums = [2,2,0,0]
// Output: 0
// Explanation: There are no special subsequences in [2,2,0,0].
// Example 3:

// Input: nums = [0,1,2,0,1,2]
// Output: 7
// Explanation: The special subsequences are:
// - [0,1,2,0,1,2]
// - [0,1,2,0,1,2]
// - [0,1,2,0,1,2]
// - [0,1,2,0,1,2]
// - [0,1,2,0,1,2]
// - [0,1,2,0,1,2]
// - [0,1,2,0,1,2]

// Constraints:

// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 2

// Hints:
// Can we first solve a simpler problem? Counting the number of subsequences with 1s followed by 0s.
// How can we keep track of the partially matched subsequences to help us find the answer?

// Testcase:
// [0,1,2,2]

// Output:
// 3

// Runtime: 272 ms, faster than 85.71% of C++ online submissions for Count Number of Special Subsequences.
// Memory Usage: 233.1 MB, less than 85.71% of C++ online submissions for Count Number of Special Subsequences.

class Solution
{
public:
    int countSpecialSubsequences(vector<int> &nums)
    {
        int sz = nums.size();

        int64_t MOD = 1000000007;

        std::vector<vector<int64_t>> dp(3, vector<int64_t>(sz, 0));

        // DP to hold the intermediate results
        dp[0][0] = (nums[0] == 0) ? 1 : 0;

        // For 0, 1, and 2 - For the sequence
        for (auto i = 0; i < 3; i++)
        {
            for (auto j = 1; j < sz; j++)
            {
                if (i == nums[j])
                {
                    // Numbers are same, e.g. 0,0 or 1,1, or 2,2
                    // Multiplied previous value by 2 because we can either choose nums[j] or not
                    dp[i][j] = ((2 * dp[i][j - 1]) + ((i == 0) ? 1 : dp[i - 1][j - 1])) % MOD;
                }
                else
                {
                    // Numbers are not same, use the previous value
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[2][sz - 1];
    }
};