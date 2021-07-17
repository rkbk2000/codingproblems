// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].  An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Return true if and only if the given array nums is monotonic.

// Example 1:

// Input: nums = [1,2,2,3]
// Output: true
// Example 2:

// Input: nums = [6,5,4,4]
// Output: true
// Example 3:

// Input: nums = [1,3,2]
// Output: false
// Example 4:

// Input: nums = [1,2,4,5]
// Output: true
// Example 5:

// Input: nums = [1,1,1]
// Output: true

// Note:

// 1 <= nums.length <= 50000
// -100000 <= nums[i] <= 100000

// Test case:
// [1,2,2,3]
// [6,5,4,4]
// [1,3,2]
// [1,2,4,5]
// [1,1,1]

// Output:
// true
// true
// false
// true
// true

// https://leetcode.com/problems/monotonic-array/

// Runtime: 52 ms, faster than 97.49% of C++ online submissions for Monotonic Array.
// Memory Usage: 52.7 MB, less than 77.26% of C++ online submissions for Monotonic Array.
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        return std::is_sorted(nums.begin(), nums.end()) ||
               std::is_sorted(nums.begin(), nums.end(), std::greater<int>());
    }
};

// Runtime: 76 ms, faster than 29.07% of C++ online submissions for Monotonic Array.
// Memory Usage: 52.7 MB, less than 77.26% of C++ online submissions for Monotonic Array.
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        auto asc = true, desc = true;
        for (auto i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                desc = false;
            }
            if (nums[i] < nums[i - 1])
            {
                asc = false;
            }
        }
        return asc || desc;
    }
};