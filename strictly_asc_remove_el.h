// Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element,
// or false otherwise. If the array is already strictly increasing, return true.

// The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

// Example 1:

// Input: nums = [1,2,10,5,7]
// Output: true
// Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
// [1,2,5,7] is strictly increasing, so return true.
// Example 2:

// Input: nums = [2,3,1,2]
// Output: false
// Explanation:
// [3,1,2] is the result of removing the element at index 0.
// [2,1,2] is the result of removing the element at index 1.
// [2,3,2] is the result of removing the element at index 2.
// [2,3,1] is the result of removing the element at index 3.
// No resulting array is strictly increasing, so return false.
// Example 3:

// Input: nums = [1,1,1]
// Output: false
// Explanation: The result of removing any element is [1,1].
// [1,1] is not strictly increasing, so return false.
// Example 4:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is already strictly increasing, so return true.

// Constraints:

// 2 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/submissions/
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        if (nums.size() == 2)
        {
            return true;
        }

        auto n = (int)nums.size();
        auto flipIdx = -1, count = 0;
        for (auto idx = 1; idx < n; ++idx)
        {
            if (nums[idx] <= nums[idx - 1])
            {
                flipIdx = idx;
                count++;
            }
        }

        if (count > 1)
        {
            return false;
        }

        if ((flipIdx == -1) || (flipIdx == 1) || (flipIdx == (n - 1)))
        {
            // No flip at all, already sorted, or first or last index
            return true;
        }

        // Check if flipIndex is removed
        if (nums[flipIdx - 1] < nums[flipIdx + 1])
        {
            return true;
        }
        // Check if flipIndex -1 got removed
        if (nums[flipIdx - 2] < nums[flipIdx])
        {
            return true;
        }
        return false;
    }
};