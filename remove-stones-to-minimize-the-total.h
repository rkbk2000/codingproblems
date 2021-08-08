// You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following operation exactly k times:

// Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
// Notice that you can apply the operation on the same pile more than once.

// Return the minimum possible total number of stones remaining after applying the k operations.

// floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).

// Example 1:

// Input: piles = [5,4,9], k = 2
// Output: 12
// Explanation: Steps of a possible scenario are:
// - Apply the operation on pile 2. The resulting piles are [5,4,5].
// - Apply the operation on pile 0. The resulting piles are [3,4,5].
// The total number of stones in [3,4,5] is 12.
// Example 2:

// Input: piles = [4,3,6,7], k = 3
// Output: 12
// Explanation: Steps of a possible scenario are:
// - Apply the operation on pile 3. The resulting piles are [4,3,3,7].
// - Apply the operation on pile 4. The resulting piles are [4,3,3,4].
// - Apply the operation on pile 0. The resulting piles are [2,3,3,4].
// The total number of stones in [2,3,3,4] is 12.

// Constraints:

// 1 <= piles.length <= 10^5
// 1 <= piles[i] <= 10^4
// 1 <= k <= 10^5

// Hints:
// Choose the pile with the maximum number of stones each time.
// Use a data structure that helps you find the mentioned pile each time efficiently.
// One such data structure is a Priority Queue.

// 08/08/2021 08:29	Accepted	1892 ms	283 MB	cpp

class SolutionMS
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        std::multiset<int, std::greater<int>> stones(piles.begin(), piles.end());
        for (int i = 0; i < k; i++)
        {
            int temp = floor(*stones.begin() / 2) + ((*stones.begin() % 2) ? 1 : 0);
            // cout<<"temp is: "<< temp <<endl;
            stones.erase(stones.begin());
            stones.insert(temp);
        }
        auto sum = std::accumulate(stones.begin(), stones.end(), 0);
        return sum;
    }
};

// Optimal solution
// Runtime: 492 ms, faster than 100.00% of C++ online submissions for Remove Stones to Minimize the Total.
// Memory Usage: 98.7 MB, less than 88.89% of C++ online submissions for Remove Stones to Minimize the Total.
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        std::priority_queue<int> stones(piles.begin(), piles.end());

        for (int i = 0; i < k; i++)
        {
            int temp = (stones.top() + 1) / 2;
            stones.pop();
            stones.push(temp);
        }
        auto sum = 0;
        while (!stones.empty())
        {
            sum += stones.top();
            stones.pop();
        }
        return sum;
    }
};