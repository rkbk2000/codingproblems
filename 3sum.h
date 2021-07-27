// https://leetcode.com/problems/3sum/

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []

// Constraints:

// 0 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5

// Hints:
// So, we essentially need to find three numbers x, y, and z such that they add up to the given value. If we fix one of the numbers say x, we are left with the two-sum problem at hand!

// For the two-sum problem, if we fix one of the numbers, say
// x
// , we have to scan the entire array to find the next number
// y
// which is
// value - x
// where value is the input parameter. Can we change our array somehow so that this search becomes faster?

// The second train of thought for two-sum is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

// Runtime: 48 ms, faster than 98.79% of C++ online submissions for 3Sum.
// Memory Usage: 20.1 MB, less than 66.46% of C++ online submissions for 3Sum.
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int>> result;

        for (auto i = 0; i < sz - 2; i++)
        {
            // Either first element or both are not same
            if (i == 0 || nums[i] != nums[i - 1])
            {
                int x = -nums[i];
                if (x < 0)
                {
                    // We have reached the position from which we have all positive numbers only
                    break;
                }

                int l = i + 1, r = sz - 1;

                // Use binary search
                while (l < r)
                {
                    auto sum = nums[l] + nums[r];
                    if (sum == x)
                    {
                        // We have found the correct triplet
                        result.push_back({nums[i], nums[l], nums[r]});

                        // Skip the same numbers on left
                        while (l + 1 < r && nums[l] == nums[l + 1])
                            l++;

                        // Skip the same numbers on right
                        while (l + 1 < r && nums[r] == nums[r - 1])
                            r--;
                        l++;
                        r--;
                    }
                    else if (sum < x)
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

// O(n^3) solution
// Runtime: 1356 ms 5%
// Memory Usage: 366.3 MB 5%
class Solution1356
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int sz = nums.size();

        set<vector<int>> ans;

        auto i = 0;
        while (i < sz)
        {
            auto x = nums[i];
            int rem = 0 - x;
            auto yz = twoSum(nums, i + 1, rem);

            for (auto &row : yz)
            {
                ans.emplace(vector<int>{x, row[0], row[1]});
            }

            // Skip all the numbers that are same
            while (i < sz && x == nums[i])
            {
                i++;
            }
        }
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }

    vector<vector<int>> twoSum(const vector<int> &arr, int start, int sum)
    {
        unordered_multiset<int> s;
        vector<vector<int>> result;

        for (int i = start; i < arr.size(); i++)
        {
            int x = sum - arr[i];
            auto pos = s.equal_range(x);
            if (pos.first != s.end())
            {
                result.push_back({x, arr[i]});
                s.erase(pos.first, pos.second);
            }
            else
            {
                s.insert(arr[i]);
            }
        }
        return result;
    }
};