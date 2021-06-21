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

        // Use a thread pool for concurrent execution, lockless
        auto qSize = queries.size();
        vector<int> result(qSize);

        int NumThreads = thread::hardware_concurrency();

        vector<thread> ThreadPool;
        int taskPerThread = qSize / NumThreads;
        int extra = qSize % NumThreads;
        for (auto i = 0; i < NumThreads; i++)
        {
            auto start = taskPerThread * i;
            auto end = start + taskPerThread;
            if (i == (NumThreads - 1))
            {
                end += extra;
            }
            ThreadPool.push_back(thread(&Solution::findAbsMin, this, std::ref(numindex), queries, start, end, std::ref(result)));
        }

        for (auto &t : ThreadPool)
        {
            t.join();
        }
        //for (taskIndex=0; taskIndex < queries.size(); taskIndex++) {
        //    findAbsMin(numindex, queries, result);
        //}
        return result;
    }

    void findAbsMin(const vector<int> (&numindex)[101], const vector<vector<int>> &queries, int x, int y, vector<int> &result)
    {
        for (auto curIdx = x; curIdx < y; ++curIdx)
        {
            auto li = queries[curIdx][0], ri = queries[curIdx][1];
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
    }
};