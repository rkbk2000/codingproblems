// https://leetcode.com/problems/beautiful-array/

// An array nums of length n is beautiful if:

// nums is a permutation of the integers in the range [1, n].
// For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
// Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.

// Example 1:

// Input: n = 4
// Output: [2,1,4,3]
// Example 2:

// Input: n = 5
// Output: [3,1,2,5,4]

// Constraints:

// 1 <= n <= 1000

// Solution:
// Approach 1: Divide and Conquer
// Intuition

// First, notice that the condition is equivalent to saying that A has no arithmetic subsequence. We'll use the term "arithmetic-free" interchangeably with "beautiful".

// One way is to guess that we should divide and conquer. One reason for this is that the condition is linear, so if the condition is satisfied by variables taking on values (1, 2, ..., n), it is satisfied by those variables taking on values (a + b, a + 2*b, a + 3*b, ..., a + (n-1)*b) instead.

// If we perform a divide and conquer, then we have two parts left and right, such that each part is arithmetic-free, and we only want that a triple from both parts is not arithmetic. Looking at the conditions:

// 2*A[k] = A[i] + A[j]
// (i < k < j), i from left, j from right
// we can guess that because the left hand side 2*A[k] is even, we can choose left to have all odd elements, and right to have all even elements.

// Another way we could arrive at this is to try to place a number in the middle, like 5. We will have 4 and 6 say, to the left of 5, and 7 to the right of 6, etc. We see that in general, odd numbers move towards one direction and even numbers towards another direction.

// One final way we could arrive at this is to inspect possible answers arrived at by brute force. On experimentation, we see that many answers have all the odd elements to one side, and all the even elements to the other side, with only minor variation.

// Algorithm

// Looking at the elements 1, 2, ..., N, there are (N+1) / 2 odd numbers and N / 2 even numbers.

// We solve for elements 1, 2, ..., (N+1) / 2 and map these numbers onto 1, 3, 5, .... Similarly, we solve for elements 1, 2, ..., N/2 and map these numbers onto 2, 4, 6, ....

// We can compose these solutions by concatenating them, since an arithmetic sequence never starts and ends with elements of different parity.

// We memoize the result to arrive at the answer quicker.

// Runtime: 4 ms, faster than 74.56% of C++ online submissions for Beautiful Array.
// Memory Usage: 8.1 MB, less than 46.29% of C++ online submissions for Beautiful Array.

// Test case:
// 4
// 10

// Output:
// [1,3,2,4]
// [1,9,5,3,7,2,10,6,4,8]

// Expected:
// [2,1,4,3] // output, expected are same, only  orders differ
// [1,9,5,3,7,2,10,6,4,8]

class Solution
{
    unordered_map<int, vector<int>> numbers;

public:
    vector<int> beautifulArray(int n)
    {
        auto it = numbers.find(n);
        if (it != numbers.end())
        {
            return it->second;
        }

        vector<int> result(n);
        if (n == 1)
        {
            result[0] = 1;
        }
        else
        {
            auto i = 0;

            // Odd values on one side
            for (auto val : beautifulArray((n + 1) / 2))
            {
                result[i++] = 2 * val - 1;
            }

            // Even values
            for (auto val : beautifulArray(n / 2))
            {
                result[i++] = 2 * val;
            }
        }
        numbers.emplace(n, result);
        return result;
    }
};

// Same solution but, seperate recursive function
class SolutionRec
{
    unordered_map<int, vector<int>> numbers;

public:
    vector<int> beautifulArray(int n)
    {
        return getVals(n);
    }

    vector<int> getVals(int n)
    {
        auto it = numbers.find(n);
        if (it != numbers.end())
        {
            return it->second;
        }

        vector<int> result(n);
        if (n == 1)
        {
            result[0] = 1;
        }
        else
        {
            auto i = 0;

            // Odd values on one side
            for (auto val : getVals((n + 1) / 2))
            {
                result[i++] = 2 * val - 1;
            }

            // Even values
            for (auto val : getVals(n / 2))
            {
                result[i++] = 2 * val;
            }
        }
        numbers.emplace(n, result);
        return result;
    }
};