// https://leetcode.com/problems/minimum-absolute-difference-queries/
class Solution
{

public:
    vector<int> minDifference(const vector<int> &nums, const vector<vector<int>> &queries)
    {

        // Range of values for nums[i] is 1 to 100, capture the indexes for each number
        vector<int> numindex[101];
        auto i = 0;
        for (auto v : nums)
        {
            numindex[v].push_back(i++);
        }

        vector<int> result(queries.size());

        for (auto qi = 0; qi < queries.size(); qi++)
        {
            auto li = queries[qi][0], ri = queries[qi][1];
            auto absmin = INT_MAX;
            auto oldVal = -1;
            // Go through our index vector and check if the value exists
            for (auto i = 1; i < 101; i++)
            {
                // We are given a sub array from li to ri
                if (numindex[i].empty())
                {
                    // The number is not present at all
                    continue;
                }
                // Chheck from li to index greater than ri in the index array to check the range.
                auto idx1 = std::lower_bound(numindex[i].begin(), numindex[i].end(), li) - numindex[i].begin();
                auto idx2 = std::upper_bound(numindex[i].begin(), numindex[i].end(), ri) - numindex[i].begin();
                if (idx1 >= idx2)
                {
                    // Out of range, skip
                    continue;
                }
                if (oldVal != -1)
                {
                    absmin = min(i - oldVal, absmin);
                }

                if (absmin == 1)
                {
                    // Minimum possible difference found, no need to continue, break
                    break;
                }
                oldVal = i;
            }
            result[curIdx] = (absmin == INT_MAX) ? -1 : absmin;
        }
        return result;
    }
};