// Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

// Implement the Solution class:

// Solution(int[] nums) Initializes the object with the integer array nums.
// int[] reset() Resets the array to its original configuration and returns it.
// int[] shuffle() Returns a random shuffling of the array.

// Example 1:

// Input
// ["Solution", "shuffle", "reset", "shuffle"]
// [[[1, 2, 3]], [], [], []]
// Output
// [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

// Explanation
// Solution solution = new Solution([1, 2, 3]);
// solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
//                        // Any permutation of [1,2,3] must be equally likely to be returned.
//                        // Example: return [3, 1, 2]
// solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
// solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

// Constraints:

// 1 <= nums.length <= 200
// -106 <= nums[i] <= 106
// All the elements of nums are unique.
// At most 5 * 104 calls in total will be made to reset and shuffle.

// https://leetcode.com/problems/shuffle-an-array/

// Testcase:
// ["Solution","shuffle","reset","shuffle"]
// [[[1,2,3]],[],[],[]]
// ["Solution","shuffle","reset","shuffle","shuffle", "shuffle","shuffle", "reset", "reset"]
// [[[1,2,3,4,5,6,7,8,9,10]],[],[],[],[],[],[],[],[]]

// Output:
// [null,[2,1,3],[1,2,3],[2,1,3]]
// [null,[7,2,4,5,6,8,9,1,3,10],[1,2,3,4,5,6,7,8,9,10],[7,2,4,5,6,8,9,1,3,10],[7,2,4,5,6,8,9,1,3,10],[7,2,4,5,6,8,9,1,3,10],[7,2,4,5,6,8,9,1,3,10],[1,2,3,4,5,6,7,8,9,10],[1,2,3,4,5,6,7,8,9,10]]

// 10 / 10 test cases passed.
// Status: Accepted
// Runtime: 112 ms, 36%
// Memory Usage: 90.2 MB, 89%

class Solution
{
    vector<int> orgvals;

public:
    Solution(vector<int> &nums) : orgvals(nums)
    {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return orgvals;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        auto vals = orgvals;
        // Time based seed
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(vals.begin(), vals.end(), std::default_random_engine(seed));
        return vals;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

// Runtime: 100 ms, faster than 62.28% of C++ online submissions for Shuffle an Array.
// Memory Usage: 90.3 MB, less than 66.98% of C++ online submissions for Shuffle an Array.

// Another solution
class SolutionUID
{
    vector<int> orgvals;
    size_t sz;
    std::default_random_engine generator;

public:
    Solution(vector<int> &nums) : orgvals(nums), sz(nums.size())
    {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return orgvals;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        auto vals = orgvals;
        for (auto i = 0; i < vals.size(); i++)
        {
            std::uniform_int_distribution<decltype(i)> d(i, sz - 1);
            std::swap(vals[i], vals[d(generator)]);
        }
        return vals;
    }
};
