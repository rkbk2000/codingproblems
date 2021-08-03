// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space.

// Example 1:

// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
// Example 2:

// Input: n = 2
// Output: [1,2]

// Constraints:

// 1 <= n <= 5 * 10^4

// Testcase:
// 13

// Output:
// [1,10,11,12,13,2,3,4,5,6,7,8,9]

// Runtime: 8 ms, faster than 82.07% of C++ online submissions for Lexicographical Numbers.
// Memory Usage: 11.6 MB, less than 50.23% of C++ online submissions for Lexicographical Numbers.

class Solution
{
    vector<int> result;

public:
    vector<int> lexicalOrder(int n)
    {
        backtrack(0, n);
        return result;
    }

    void backtrack(int from, int n)
    {
        auto idxstart = (from == 0) ? 1 : 0;

        for (auto i = idxstart; i <= 9; i++)
        {
            auto val = (from * 10) + i;

            if (val <= n)
            {
                result.push_back(val);
                backtrack(val, n);
            }
        }
    }
};