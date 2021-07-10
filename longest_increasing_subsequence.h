// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Constraints:

// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

// [10,9,2,5,3,7,101,18]
// [7,7,7,7,7,7,7]
// [0,1,0,3,2,3]
// [9,8,7,6,5,4,3,2,1]
// [1]
// [4,10,4,3,8,9]
// 4
// 1
// 4
// 1
// 1
// 3

// https://leetcode.com/problems/longest-increasing-subsequence

// Solution 1: hand coded binary search
// Runtime: 20 ms, faster than 70.08% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 10.6 MB, less than 13.48% of C++ online submissions for Longest Increasing Subsequence.

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int sz = nums.size();

        vector<int> lis(sz, 0);
        lis[0] = nums[0];

        int lmax = 1;

        for (auto i = 0; i < sz; i++)
        {
            auto n = nums[i];
            if (n > lis[lmax - 1])
            {
                lis[lmax++] = n;
            }
            else
            {
                auto pos = binsearch(lis, lmax, n);
                lis[pos] = n;
            }
        }
        return lmax;
    }

    int binsearch(const vector<int> &lis, int sz, int n)
    {
        int l = 0, r = sz - 1;
        int mid = (l + r) / 2;

        while (l < r)
        {
            if (lis[mid] == n)
            {
                return mid;
            }

            if (lis[mid] < n)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
            mid = (l + r) / 2;
        }
        return l;
    }
};

// Solution 2: using lower_bound and DP
// Runtime 76.08%
// Memory Usage: 10.6 MB, less than 13.48%
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int sz = nums.size();
        vector<int> lis(sz, 0);

        int lmax = 1;

        lis[0] = nums[0];

        for (auto i = 1; i < sz; i++)
        {
            // Lowest value found, posibly a new subarray
            if (nums[i] < lis[0])
            {
                lis[0] = nums[i];
            }
            else if (nums[i] > lis[lmax - 1])
            {
                // Maximum value found till now, replace current max with new max
                lis[lmax++] = nums[i];
            }
            else
            {
                // Identify the right position
                auto it = std::lower_bound(lis.begin(), lis.begin() + (lmax - 1), nums[i]);
                *it = nums[i];
            }
        }
        return lmax;
    }
};