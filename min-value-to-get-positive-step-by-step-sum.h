// Given an array of integers nums, you start with an initial positive value startValue.

// In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

// Return the minimum positive value of startValue such that the step by step sum is never less than 1.

// Example 1:

// Input: nums = [-3,2,-3,4,2]
// Output: 5
// Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
//                 step by step sum
//                 startValue = 4 | startValue = 5 | nums
//                   (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
//                   (1 +2 ) = 3  | (2 +2 ) = 4    |   2
//                   (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
//                   (0 +4 ) = 4  | (1 +4 ) = 5    |   4
//                   (4 +2 ) = 6  | (5 +2 ) = 7    |   2
// Example 2:

// Input: nums = [1,2]
// Output: 1
// Explanation: Minimum start value should be positive.
// Example 3:

// Input: nums = [1,-2,-3]
// Output: 5

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100
// Accepted

// Test case:
// [-3,2,-3,4,2]
// [1,2]
// [1,-2,-3]
// [-3,3]
// [3,-3]
// [0,0,0]
// [2,3,5,-5,-1]
// [3,4,5,6,7]

// Output:
// 5
// 1
// 5
// 4
// 1
// 1
// 1
// 1

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
// Memory Usage: 7.3 MB, less than 55.18% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

class Solution
{
public:
  int minStartValue(vector<int> &nums)
  {
    // Find the minimum prefix sum
    auto ps = nums[0], minp = nums[0];
    for (auto i = 1; i < nums.size(); i++)
    {
      ps += nums[i];
      minp = std::min(minp, ps);
    }
    return (minp < 0) ? (abs(minp) + 1) : 1;
  }
};