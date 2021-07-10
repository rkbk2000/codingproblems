// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4
// Example 4:

// Input: nums = [1,3,5,6], target = 0
// Output: 0
// Example 5:

// Input: nums = [1], target = 0
// Output: 0

// Constraints:

// 1 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// nums contains distinct values sorted in ascending order.
// -10^4 <= target <= 10^4

// // Testcase:
// [1,3,5,6]
// 5
// [1,3,5,6]
// 2
// [1,3,5,6]
// 7
// [1,3,5,6]
// 0
// [1]
// 0
// [1,2,3,5]
// 4

// // Output:
// 2
// 1
// 4
// 0
// 0
// 3

// // One liner
// Runtime: 12 ms, faster than 5.03% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.7 MB, less than 52.34% of C++ online submissions for Search Insert Position.
class SolutionLB
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

// Binary search, not any better
// Runtime: 12 ms, faster than 5.03% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.6 MB, less than 52.34% of C++ online submissions for Search Insert Position.

class SolutionBS
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        int mid = (l + r) / 2;

        while (l < r)
        {
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
            mid = (l + r) >> 1;
        }
        return l;
    }
};

// Best solution - combination of find and lower bound
// Runtime: 4 ms, faster than 82.43% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.7 MB, less than 52.34% of C++ online submissions for Search Insert Position.
class SolutionFLB
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        auto it = std::find(nums.begin(), nums.end(), target);
        if (it != nums.end())
        {
            return it - nums.begin();
        }
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};