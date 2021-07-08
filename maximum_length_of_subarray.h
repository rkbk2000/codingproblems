// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

// Example 1:

// Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// Output: 3
// Explanation: The repeated subarray with maximum length is [3,2,1].
// Example 2:

// Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
// Output: 5

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 100

// Runtime 640 ms, memory 43%
// Hint : Use dynamic programming. dp[i][j] will be the answer for inputs A[i:], B[j:].
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int ns1 = nums1.size(), ns2 = nums2.size();
        vector<vector<int>> dp(ns1);
        auto lmax = 0;
        for (auto i = 0; i < ns1; i++)
        {
            dp[i] = vector<int>(ns2, 0);
            for (auto j = 0; j < ns2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                    {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                }
                lmax = std::max(lmax, dp[i][j]);
            }
        }
        return lmax;
    }
};

// Runtime: 632 ms, faster than 5.07% of C++ online submissions for Maximum Length of Repeated Subarray.
// Memory Usage: 109 MB, less than 29.25% of C++ online submissions for Maximum Length of Repeated Subarray.

// Solution 2: not any better
class Solution2
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int ns1 = nums1.size(), ns2 = nums2.size();

        vector<vector<int>> dp(ns1 + 1);

        dp[0] = vector<int>(ns2 + 1, 0);
        auto lmax = 0;
        for (auto i = 1; i <= ns1; i++)
        {
            dp[i] = vector<int>(ns2 + 1, 0);
            for (auto j = 1; j <= ns2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1] + 1;
                }
                lmax = std::max(lmax, dp[i][j]);
            }
        }
        return lmax;
    }
};