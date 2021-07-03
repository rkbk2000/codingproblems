// Runtime: 16 ms, faster than 8.06% of C++ online submissions for Find Lucky Integer in an Array.
// Memory Usage: 10.3 MB, less than 23.10% of C++ online submissions for Find Lucky Integer in an Array.

// https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/

// Testcase
// [2,2,3,4]
// [1,2,2,3,3,3]
// [2,2,2,3,3]
// [5]
// [7,7,7,7,7,7,7]
// [1]
// [2,3,4]

// Output
// 2
// 3
// -1
// -1
// 7
// 1
// -1
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        map<int, int, std::greater<int>> counts;
        for (auto i = 0; i < arr.size(); ++i)
        {
            ++counts[arr[i]];
        }
        for (auto it = counts.begin(); it != counts.end(); ++it)
        {
            if (it->first == it->second)
            {
                return it->first;
            }
        }
        return -1;
    }
};

// Faster version
// Runtime: 8 ms, faster than 56.04% of C++ online submissions for Find Lucky Integer in an Array.
// Memory Usage: 10.1 MB, less than 78.87% of C++ online submissions for Find Lucky Integer in an Array.

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        array<int, 501> counts{0};

        for (auto i = 0; i < arr.size(); ++i)
        {
            ++counts[arr[i]];
        }

        for (auto i = 500; i > 0; --i)
        {
            if (i == counts[i])
            {
                return i;
            }
        }
        return -1;
    }
};

// Improved version
// Runtime: 4 ms, faster than 93.02% of C++ online submissions for Find Lucky Integer in an Array.
// Memory Usage: 10.1 MB, less than 78.87% of C++ online submissions for Find Lucky Integer in an Array.

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        array<int, 501> counts{0};
        int size = arr.size();

        for (auto i = 0; i < size; ++i)
        {
            ++counts[arr[i]];
        }

        for (auto i = size; i > 0; --i)
        {
            if (i == counts[i])
            {
                return i;
            }
        }
        return -1;
    }
};
