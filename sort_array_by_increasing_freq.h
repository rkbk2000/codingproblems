// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

// Example 1:

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100

// Test case:
// [1,1,2,2,2,3]
// [2,3,1,3,2]
// [-1,1,-6,4,5,-6,1,4,1]

// Output:
// [3,1,1,2,2,2]
// [1,3,3,2,2]
// [5,-1,4,4,-6,-6,1,1,1]
// Runtime: 8 ms, faster than 73.16% of C++ online submissions for Sort Array by Increasing Frequency.
// Memory Usage: 11.3 MB, less than 61.90% of C++ online submissions for Sort Array by Increasing Frequency.
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution
{
    // Second is the frequency and first is the number
    typedef pair<int, int> pe;
    class valcompare
    {
    public:
        bool operator()(const pe &l, const pe &r) const
        {
            if (l.second == r.second)
            {
                return l.first < r.first;
            }
            return l.second > r.second;
        }
    };

public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (auto &v : nums)
        {
            if (freq.find(v) != freq.end())
            {
                freq[v]++;
            }
            else
            {
                freq[v] = 1;
            }
        }
        // Now sort them

        priority_queue<pe, vector<pe>, valcompare> pq;
        for (auto &it : freq)
        {
            pq.emplace(it.first, it.second);
        }

        vector<int> result(nums.size());

        for (auto it = result.begin(); it != result.end();)
        {
            auto val = pq.top();
            std::fill(it, it + val.second, val.first);
            advance(it, val.second);
            pq.pop();
        }
        return result;
    }
};

// Solution using Vector - better space
// Runtime: 8 ms, faster than 73.16% of C++ online submissions for Sort Array by Increasing Frequency.
// Memory Usage: 11.2 MB, less than 81.08% of C++ online submissions for Sort Array by Increasing Frequency.
class SolutionVec
{
    // Second is the frequency and first is the number
    typedef pair<int, int> pe;
    class valcompare
    {
    public:
        bool operator()(const pe &l, const pe &r) const
        {
            if (l.second == r.second)
            {
                return l.first < r.first;
            }
            return l.second > r.second;
        }
    };

public:
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> freq(201, 0);

        for (auto &v : nums)
        {
            freq[v + 100]++;
        }

        // Now sort them, based on the rule
        priority_queue<pe, vector<pe>, valcompare> pq;
        for (auto i = 0; i < 201; ++i)
        {
            if (freq[i] != 0)
            {
                pq.emplace(i - 100, freq[i]);
            }
        }

        vector<int> result(nums.size());

        for (auto it = result.begin(); it != result.end();)
        {
            auto val = pq.top();
            std::fill(it, it + val.second, val.first);
            advance(it, val.second);
            pq.pop();
        }
        return result;
    }
};