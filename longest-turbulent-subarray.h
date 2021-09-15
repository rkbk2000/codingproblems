// 978. Longest Turbulent Subarray
// https://leetcode.com/problems/longest-turbulent-subarray/submissions/

// Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

// A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

// More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

// For i <= k < j:
// arr[k] > arr[k + 1] when k is odd, and
// arr[k] < arr[k + 1] when k is even.
// Or, for i <= k < j:
// arr[k] > arr[k + 1] when k is even, and
// arr[k] < arr[k + 1] when k is odd.

// Example 1:

// Input: arr = [9,4,2,10,7,8,8,1,9]
// Output: 5
// Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
// Example 2:

// Input: arr = [4,8,12,16]
// Output: 2
// Example 3:

// Input: arr = [100]
// Output: 1

// Constraints:

// 1 <= arr.length <= 4 * 10^4
// 0 <= arr[i] <= 10^9

// Runtime: 72 ms, faster than 72.39% of C++ online submissions for Longest Turbulent Subarray.
// Memory Usage: 40.2 MB, less than 82.01% of C++ online submissions for Longest Turbulent Subarray.

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int sz = arr.size(), result = 1, start = 0;

        auto comp = [](int a, int b) -> int
        {
            if (a == b)
                return 0;
            if (a < b)
                return -1;
            return 1;
        };

        for (int i = 1; i < sz; i++)
        {
            auto c = comp(arr[i - 1], arr[i]);
            if (c == 0)
            {
                // Equal
                start = i;
            }
            else if (i == sz - 1 || (c * comp(arr[i], arr[i + 1]) != -1))
            {
                // Not alternating
                result = std::max(result, i - start + 1);
                start = i;
            }
        }
        return result;
    }
};