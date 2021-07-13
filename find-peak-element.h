
// A peak element is an element that is strictly greater than its neighbors.

// Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

// Constraints:

// 1 <= nums.length <= 1000
// -2^31 <= nums[i] <= 2^31 - 1
// nums[i] != nums[i + 1] for all valid i.
// https://leetcode.com/problems/find-peak-element/

// Runtime: 8 ms, faster than 12.53% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.9 MB, less than 46.74% of C++ online submissions for Find Peak Element.

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // Binary search could be used to find the peak as it runs in O(logN)
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

// Recursive takes 16 ms, but less memory
class SolutionRec
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // Binary search could be used to find the peak as it runs in O(logN)
        auto ans = bsearch(nums, 0, nums.size() - 1);
        return ans;
    }

    int bsearch(const vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return left;
        }
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            return bsearch(nums, left, mid);
        }
        else
        {
            return bsearch(nums, mid + 1, right);
        }
    }
};