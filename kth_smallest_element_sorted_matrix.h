// Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
// Example 2:

// Input: matrix = [[-5]], k = 1
// Output: -5

// Constraints:

// n == matrix.length
// n == matrix[i].length
// 1 <= n <= 300
// -10^9 <= matrix[i][j] <= 10^9
// All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
// 1 <= k <= n^2
// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3805/
// Speed 33%

// Test case:
// [[1,5,9],[10,11,13],[12,13,15]]
// 8
// [[-5]]
// 1
// [[1,2,3],[4,5,6],[7,8,9]]
// 1
// [[1,2,3],[4,5,6],[7,8,9]]
// 9
// [[1,2,3],[4,5,6],[7,8,9]]
// 6
// Output:
// 13
// -5
// 1
// 9
// 6
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        std::vector<int> nums(n * n);
        auto cnt = 0;
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                nums[cnt++] = matrix[i][j];
            }
        }
        std::partial_sort(nums.begin(), nums.begin() + k, nums.end());
        return nums[k - 1];
    }
};

// Using pq
// Time - 40%, memory - 24%
class SolutionPQ
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        priority_queue<int, vector<int>, std::greater<int>> pq;

        auto cnt = 0;
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                pq.emplace(matrix[i][j]);
            }
        }
        for (auto i = 1; i < k; i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// Using multi set - worst performance
// Runtime - 13%, Memory - very high, 22.4 MB
class SolutionMS
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        multiset<int> pq;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                pq.emplace(matrix[i][j]);
            }
        }
        auto it = pq.begin();
        for (auto i = 1; i < k; i++)
        {
            it++;
        }
        return *it;
    }
};

// Use  matrix comparison itself. For each element element in the same row and same column are always greater