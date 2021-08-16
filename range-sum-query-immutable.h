// https://leetcode.com/problems/range-sum-query-immutable/

// 303. Range Sum Query - Immutable
// Easy

// 1482

// 1455

// Add to List

// Share
// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

// Constraints:

// 1 <= nums.length <= 10^4
// -10^5 <= nums[i] <= 10^5
// 0 <= left <= right < nums.length
// At most 10^4 calls will be made to sumRange.

// Runtime: 104 ms, faster than 22.38% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 17 MB, less than 71.79% of C++ online submissions for Range Sum Query - Immutable.

class NumArray
{
    vector<int> &arr;

public:
    NumArray(vector<int> &nums) : arr(nums)
    {
    }

    int sumRange(int left, int right)
    {
        return std::accumulate(arr.begin() + left, arr.begin() + right + 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Runtime: 24 ms, faster than 57.48% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 16.9 MB, less than 99.77% of C++ online submissions for Range Sum Query - Immutable.

class NumArrayBetter
{
    vector<int> sums;

public:
    NumArray(vector<int> &nums)
    {
        sums.resize(nums.size() + 1);
        sums[0] = 0;
        std::partial_sum(nums.begin(), nums.end(), sums.begin() + 1);
    }

    int sumRange(int left, int right)
    {
        return sums[right + 1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */