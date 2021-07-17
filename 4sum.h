// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9
// 283 / 283 test cases passed.
// Status: Accepted
// Runtime: 1664 ms
// Memory Usage: 13.4 MB

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> used;
        int sz = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < sz - 3; i++)
        {
            for (int j = i + 1; (j < sz - 2); j++)
            {
                for (int k = j + 1; (k < sz - 1); k++)
                {
                    for (int l = k + 1; l < sz; l++)
                    {
                        if (target == nums[i] + nums[j] + nums[k] + nums[l])
                        {
                            vector<int> cur{nums[i], nums[j], nums[k], nums[l]};
                            if (used.find(cur) == used.end())
                            {
                                ans.push_back(cur);
                                used.insert(cur);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};

// Sample 0ms submission
class Solution0ms
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
            return res;
        if (k == 2)
            return twoSum(nums, target, start);
        for (int i = start; i < nums.size(); ++i)
            if (i == start || nums[i - 1] != nums[i])
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
        return res;
    }
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        int lo = start, hi = nums.size() - 1;
        while (lo < hi)
        {
            int sum = nums[lo] + nums[hi];
            if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
                ++lo;
            else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
                --hi;
            else
                res.push_back({nums[lo++], nums[hi--]});
        }
        return res;
    }
};