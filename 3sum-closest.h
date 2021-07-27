// https://leetcode.com/problems/3sum-closest/

// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Constraints:

// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4

// Test case:
// [-1,2,1,-4]
// 1
// [1,1,1,0]
// -100

// Output:
// 2
// 2

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.8 MB, less than 60.68% of C++ online submissions for 3Sum Closest.

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        int sz = nums.size();
        int mindiff = INT_MAX;

        int result = target;
        for (auto i = 0; i < sz - 2; i++)
        {
            // Either first element or both are not same
            if (i == 0 || nums[i] != nums[i - 1])
            {
                int l = i + 1, r = sz - 1;

                // Use binary search
                while (l < r)
                {
                    auto sum = nums[i] + nums[l] + nums[r];
                    auto temp = abs(target - sum);
                    if (temp < mindiff)
                    {
                        result = sum;
                        mindiff = temp;
                    }

                    if (sum == target)
                    {
                        // We have found the correct triplet
                        return result;
                    }
                    else if (sum < target)
                    {
                        // Increment left
                        l++;
                    }
                    else
                    {
                        // Decrement right
                        r--;
                    }
                }
            }
        }

        return result;
    }
};