// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

// This is a typical backtracking problem

// Testcase:
// [1,2,2]
// [1,2,3]
// [1,2,2,2]


// Output:
// [[],[1],[1,2],[1,2,2],[2],[2,2]]
// [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
// [[],[1],[1,2],[1,2,2],[1,2,2,2],[2],[2,2],[2,2,2]]

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets II.
// Memory Usage: 7.6 MB, less than 71.51% of C++ online submissions for Subsets II.

class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        vector<int> sub;
        getSubset(nums, sub, 0);
        return result;
    }

    void getSubset(const vector<int> &nums, vector<int> &sub, int cur)
    {
        result.push_back(sub);

        for (auto i = cur; i < nums.size(); i++)
        {
            if (i > cur && nums[i] == nums[i - 1])
                continue;                // Skip duplicates
            sub.push_back(nums[i]);      // Include current
            getSubset(nums, sub, i + 1); // Explore next possibility
            sub.pop_back();              // Exclude
        }
    }
};