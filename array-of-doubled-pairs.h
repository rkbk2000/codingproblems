// https://leetcode.com/problems/array-of-doubled-pairs/

// Given an array of integers arr of even length, return true if and only if it is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.

// Example 1:

// Input: arr = [3,1,3,6]
// Output: false
// Example 2:

// Input: arr = [2,1,2,6]
// Output: false
// Example 3:

// Input: arr = [4,-2,2,-4]
// Output: true
// Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
// Example 4:

// Input: arr = [1,2,4,16,8,4]
// Output: false

// Constraints:

// 0 <= arr.length <= 3 * 10^4
// arr.length is even.
// -10^5 <= arr[i] <= 10^5

// Test cases:
// [3,1,3,6]
// [2,1,2,6]
// [4,-2,2,-4]
// [1,2,4,16,8,4]
// [0,0]
// [0,0,0,0]
// [1,2,1,1]
// [1,2,4,8]

// Output:
// false
// false
// true
// false
// true
// true
// false
// true

// Runtime: 120 ms, faster than 56.99% of C++ online submissions for Array of Doubled Pairs.
// Memory Usage: 58 MB, less than 74.07% of C++ online submissions for Array of Doubled Pairs.

class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        unordered_map<int, int> amap;
        for (auto n : arr)
        {
            auto it = amap.find(n);
            if (it != amap.end())
            {
                ++it->second;
            }
            else
            {
                amap.insert({n, 1});
            }
        }
        std::sort(arr.begin(), arr.end(), [&](int x, int y)
                  { return abs(x) < abs(y); });

        int sz = arr.size();
        for (int i = 0; i < sz; i++)
        {
            auto it1 = amap.find(arr[i]);
            if (it1 == amap.end())
            {
                // Inputs like 1,2,4,8
                continue;
            }

            auto it2 = amap.find(2 * arr[i]);
            if (it1 == amap.end() || it2 == amap.end())
            {
                return false;
            }
            --it1->second;
            --it2->second;
            if (it1->second == 0)
                amap.erase(it1);
            if (it1 != it2)
            {
                if (it2->second == 0)
                    amap.erase(it2);
            }
        }
        return true;
    }
};

// Approach 1: Greedy
// Intuition

// If x is currently the array element with the least absolute value, it must pair with 2*x, as there does not exist any other x/2 to pair with it.

// Algorithm

// Let's try to (virtually) "write" the final reordered array.

// Let's check elements in order of absolute value. When we check an element x and it isn't used, it must pair with 2*x. We will attempt to write x, 2x - if we can't, then the answer is false. If we write everything, the answer is true.

// To keep track of what we have not yet written, we will store it in a count.

// Runtime: 140 ms, faster than 41.46% of C++ online submissions for Array of Doubled Pairs.
// Memory Usage: 57.9 MB, less than 91.15% of C++ online submissions for Array of Doubled Pairs.
class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        unordered_map<int, int> amap;
        for (auto n : arr)
        {
            if (amap.count(n) == 0)
            {
                amap.insert({n, 1});
            }
            else
            {
                ++amap[n];
            }
        }
        std::sort(arr.begin(), arr.end(), [&](int x, int y)
                  { return abs(x) < abs(y); });

        for (auto n : arr)
        {
            // Check if the ith element exists
            if (amap.find(n) == amap.end() || amap[n] <= 0)
                continue;

            // Check if 2n exists
            if (amap.find(2 * n) == amap.end())
                return false;

            // Not enough entries for 2n
            if (amap[2 * n] < 0)
                return false;

            --amap[n];
            --amap[2 * n];
        }
        return true;
    }
};