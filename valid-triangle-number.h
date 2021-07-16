// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side
// lengths of a triangle.

// Example 1:

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are:
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
// Example 2:

// Input: nums = [4,2,3,4]
// Output: 4

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000

// https://leetcode.com/problems/valid-triangle-number/solution/

// Runtime : 196 ms 27.82%
// Memory Usage : 12.6 MB, 94.73%

// Test cases:
// [2,2,3]
// [2,2,3,4]
// [4,2,3,4]
// [2,2,3,4,2,2,3,4]
// [0,0,0,0]

// Output:
// 1
// 3
// 4
// 44
// 0

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sz = nums.size();

        auto ans = 0;
        for (int i = 0; i < sz - 2; i++)
        {
            auto k = i + 2;
            for (int j = i + 1; (j < sz - 1) && (nums[i] != 0); j++)
            {
                k = binsearch(nums, k, sz - 1, nums[i] + nums[j]);
                ans += k - j - 1;
            }
        }

        return ans;
    }

    int binsearch(const vector<int> &nums, int l, int r, int num)
    {
        while (l <= r && r < nums.size())
        {
            int mid = (l + r) / 2;

            if (nums[mid] >= num)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

// Using linear scan, performing better than BS
// Runtime: 136 ms, faster than 43.84% of C++ online submissions for Valid Triangle Number.
// Memory Usage: 12.7 MB, less than 94.73% of C++ online submissions for Valid Triangle Number.
class SolutionLS
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sz = nums.size();

        auto ans = 0;
        for (int i = 0; i < sz - 2; i++)
        {
            auto k = i + 2;
            for (int j = i + 1; (j < sz - 1) && (nums[i] != 0); j++)
            {
                while ((k < sz) && (nums[k] < (nums[i] + nums[j])))
                    k++;
                ans += k - j - 1;
            }
        }

        return ans;
    }
};
