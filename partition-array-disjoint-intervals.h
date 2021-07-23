// Given an array nums, partition it into two (contiguous) subarrays left and right so that:

// Every element in left is less than or equal to every element in right.
// left and right are non-empty.
// left has the smallest possible size.
// Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

// Example 1:

// Input: nums = [5,0,3,8,6]
// Output: 3
// Explanation: left = [5,0,3], right = [8,6]
// Example 2:

// Input: nums = [1,1,1,0,6,12]
// Output: 4
// Explanation: left = [1,1,1,0], right = [6,12]

// Note:

// 2 <= nums.length <= 30000
// 0 <= nums[i] <= 10^6
// It is guaranteed there is at least one way to partition nums as described.

// https://leetcode.com/problems/partition-array-into-disjoint-intervals/

// Testcase:
// [5,0,3,8,6]
// [5,0,3,8,6]
// [1,1,1,0,6,12]
// [1,2,3,4,5]
// [5,4,3,2,1,100]
// [1,2,3,4,5,100]
// [1,2]
// [2,1,5,4,3,2,1,1,1,1,11]
// [0,0,0,0,0,0]
// [26,51,40,58,42,76,30,48,79,91]
// [6,0,8,30,37,6,75,98,39,90,63,74,52,92,64]
// [29,33,6,4,42,0,10,22,62,16,46,75,100,67,70,74,87,69,73,88]

// Output:
// 3
// 4
// 1
// 5
// 1
// 1
// 10
// 1
// 1
// 2
// 11

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        // Use binary search
        // Find the minimum element
        auto minit = std::min_element(nums.begin(), nums.end());
        if (minit == nums.begin())
        {
            return 1;
        }

        // Find the max in the left partition to get the maximum
        auto maxit = std::max_element(nums.begin(), minit);

        int ans = minit - nums.begin() + 1;
        if (*maxit == *minit)
        {
            return ans;
        }

        int lmax = *maxit;
        // All numbers right to lmin should be >= lmax
        for (auto i = ans; i < nums.size(); i++)
        {
            if (nums[i] < lmax)
            {
                ans = i + 1;
                // Update the max element
                maxit = std::max_element(minit + 1, nums.begin() + i);
                if (*maxit > lmax)
                {
                    lmax = *maxit;
                }
            }
        }
        return ans;
    }
};

// Using prefix arrays
// Runtime: 24 ms, faster than 91.51% of C++ online submissions for Partition Array into Disjoint Intervals.
// Memory Usage: 21.6 MB, less than 36.74% of C++ online submissions for Partition Array into Disjoint Intervals.
class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {

        int sz = nums.size();
        vector<int> amax(sz), amin(sz);
        amax[0] = nums[0];
        amin[sz - 1] = nums.back();

        for (auto i = 1; i < sz; i++)
        {
            amax[i] = std::max(nums[i], amax[i - 1]);
        }

        for (auto i = sz - 2; i >= 0; i--)
        {
            amin[i] = std::min(nums[i], amin[i + 1]);
        }

        int ans = 0;
        for (; ans < sz - 1; ans++)
        {
            if (amax[ans] <= amin[ans + 1])
            {
                break;
            }
        }
        return ans + 1;
    }
};

// Another solution with O(1) space
class SolutionO1
{
public:
    int partitionDisjoint(vector<int> &nums)
    {

        int sz = nums.size();

        // tempmax contains the maximum found until the last min partition
        // lmax is the max from last min partition to current index till which partition gets extended
        // Inititally both are same
        int tempmax = nums[0], lmax = nums[0];
        int ans = 1;

        for (auto i = 1; i < sz; i++)
        {
            if (nums[i] < tempmax)
            {
                ans = i + 1;
                tempmax = lmax;
            }
            else
            {
                lmax = std::max(nums[i], lmax);
            }
        }
        return ans;
    }
};