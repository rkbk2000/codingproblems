// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// 442. Find All Duplicates in an Array
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []

// Constraints:

// n == nums.length
// 1 <= n <= 10^5
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.

// Runtime: 36 ms, faster than 98.69% of C++ online submissions for Find All Duplicates in an Array.
// Memory Usage: 33.6 MB, less than 74.16% of C++ online submissions for Find All Duplicates in an Array.

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int sz = nums.size();
        vector<int> result;
        for (int i = 0; i < sz; i++)
        {
            // Negate the number at its position
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            if (nums[abs(nums[i]) - 1] > 0)
                result.push_back(abs(nums[i]));
        }
        return result;
    }
};