// 350. Intersection of Two Arrays II
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

// Follow up:

// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

// Runtime: 10 ms, faster than 19.88% of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage: 10.6 MB, less than 32.89% of C++ online submissions for Intersection of Two Arrays II.

// Using two count arrays - no sorting
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> count1(1001, 0), count2(1001, 0);

        for (int i = 0; i < nums1.size(); i++)
        {
            count1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            count2[nums2[i]]++;
        }

        vector<int> result;
        for (int i = 0; i < count1.size(); i++)
        {
            auto cnt = std::min(count1[i], count2[i]);
            for (int j = 0; j < cnt; j++)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

class Solution0ms
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};