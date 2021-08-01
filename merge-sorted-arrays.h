// https://leetcode.com/problems/merge-sorted-array/

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// Constraints:

// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -10^9 <= nums1[i], nums2[j] <= 10^9

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9.1 MB, less than 29.20% of C++ online submissions for Merge Sorted Array.
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result(m + n);

        int cnt = 0, i = 0, j = 0;

        while (i < m && j < n)
        {
            while (i < m && j < n && nums1[i] <= nums2[j])
            {
                if (nums1[i] == nums2[j])
                {
                    result[cnt++] = nums2[j++];
                }
                result[cnt++] = nums1[i++];
            }
            while (i < m && j < n && nums2[j] <= nums1[i])
            {
                if (nums1[i] == nums2[j])
                {
                    result[cnt++] = nums1[i++];
                }
                result[cnt++] = nums2[j++];
            }
        }
        while (i < m)
        {
            result[cnt++] = nums1[i++];
        }
        while (j < n)
        {
            result[cnt++] = nums2[j++];
        }
        nums1 = result;
    }
};

// Using STL merge
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9.2 MB, less than 29.20% of C++ online submissions for Merge Sorted Array.
class SolutionSTL
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, result.begin());
        nums1 = result;
    }
};