
// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr

// Example 1:

// Input: arr = [4,2,1,3]
// Output: [[1,2],[2,3],[3,4]]
// Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
// Example 2:

// Input: arr = [1,3,6,10,15]
// Output: [[1,3]]
// Example 3:

// Input: arr = [3,8,-10,23,19,-4,-14,27]
// Output: [[-14,-10],[19,23],[23,27]]

// Constraints:

// 2 <= arr.length <= 10^5
// -10^6 <= arr[i] <= 10^6
// Runtime: 84 ms, faster than 24.16% of C++ online submissions for Minimum Absolute Difference.
// Memory Usage: 32.3 MB, less than 44.52% of C++ online submissions for Minimum Absolute Difference.
// https://leetcode.com/problems/minimum-absolute-difference/submissions/
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {

        // Sort and find the min at one shot
        auto min = INT_MAX;

        std::sort(arr.begin(), arr.end(), [&](int x, int y)
                  {
                      auto r = abs(x - y);
                      if (r < min)
                      {
                          min = r;
                      };
                      return x < y;
                  });

        vector<vector<int>> result;

        for (auto i = 1; i < arr.size(); ++i)
        {
            if (min == abs(arr[i] - arr[i - 1]))
            {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};