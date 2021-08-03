// https://leetcode.com/problems/subsets/

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

// Testcase:
// [1,2,3]
// [0]

// Output:
// [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
// [[],[0]]

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 7.1 MB, less than 65.58% of C++ online submissions for Subsets.

// We define a backtrack function named backtrack(first, curr) which takes the index of first element to add and a current combination as arguments.

// If the current combination is done, we add the combination to the final output.

// Otherwise, we iterate over the indexes i from first to the length of the entire sequence n.

// Add integer nums[i] into the current combination curr.

// Proceed to add more integers into the combination : backtrack(i + 1, curr).

// Backtrack by removing nums[i] from curr.
class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> sub;
        backtrack(nums, sub, 0);
        return result;
    }

    void backtrack(const vector<int> &nums, vector<int> &sub, int cur)
    {
        result.push_back(sub);

        for (auto i = cur; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);      // Include current
            backtrack(nums, sub, i + 1); // Explore next possibility
            sub.pop_back();              // Exclude
        }
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 7.1 MB, less than 65.58% of C++ online submissions for Subsets.

// Let's start from empty subset in output list. At each step one takes new integer into consideration and generates new subsets from the existing ones.

// Complexity Analysis
// Time complexity: O(N * 2^N) to generate all subsets and then copy them into output list.
// Space complexity: O(N*2^N). This is exactly the number of solutions for subsets multiplied by the number N of elements to keep for
//  each subset.
// For a given number, it could be present or absent (i.e. binary choice) in a subset solution. As as result, for N numbers,
// we would have in total 2^N choices (solutions).

class SolutionCascade
{
    vector<vector<int>> result;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        result.push_back({});
        // Cascading method using already generated subset
        for (auto n : nums)
        {

            int sz = result.size();
            for (auto j = 0; j < sz; j++)
            {
                auto temp = result[j];
                temp.push_back(n);
                result.push_back(temp);
            }
        }
        return result;
    }
};

// Lexicographic (Binary Sorted) Subsets
// Intuition

// The idea of this solution is originated from Donald E. Knuth.

// The idea is that we map each subset to a bitmask of length n, where 1 on the ith position in bitmask means the presence of nums[i] in the subset, and 0 means its absence.
// For instance, the bitmask 0..00 (all zeros) corresponds to an empty subset, and the bitmask 1..11 (all ones) corresponds to the entire input array nums.

// Hence to solve the initial problem, we just need to generate n bitmasks from 0..00 to 1..11.

// It might seem simple at first glance to generate binary numbers, but the real problem here is how to deal with zero left padding, because one has to generate bitmasks of fixed length, i.e. 001 and not just 1. For that one could use standard bit manipulation trick:
// Algorithm

//     Generate all possible binary bitmasks of length n.

//     Map a subset to each bitmask : 1 on the ith position in bitmask means the presence of nums[i] in the subset,
//     and0 means its absence.

//        Return output list.