// You are playing a video game where you are defending your city from a group of n monsters. You are given a 0-indexed integer array
// dist of size n, where dist[i] is the initial distance in meters of the ith monster from the city.
// The monsters walk toward the city at a constant speed. The speed of each monster is given to you in an integer array speed of size n,
// where speed[i] is the speed of the ith monster in meters per minute.

// The monsters start moving at minute 0. You have a weapon that you can choose to use at the start of every minute, including minute 0.
// You cannot use the weapon in the middle of a minute. The weapon can eliminate any monster that is still alive. You lose when any monster reaches your city. If a monster reaches the city exactly at the start of a minute, it counts as a loss, and the game ends before you can use your weapon in that minute.

// Return the maximum number of monsters that you can eliminate before you lose, or n if you can eliminate all the monsters before they
// reach the city.

// Example 1:

// Input: dist = [1,3,4], speed = [1,1,1]
// Output: 3
// Explanation:
// At the start of minute 0, the distances of the monsters are [1,3,4], you eliminate the first monster.
// At the start of minute 1, the distances of the monsters are [X,2,3], you don't do anything.
// At the start of minute 2, the distances of the monsters are [X,1,2], you eliminate the second monster.
// At the start of minute 3, the distances of the monsters are [X,X,1], you eliminate the third monster.
// All 3 monsters can be eliminated.
// Example 2:

// Input: dist = [1,1,2,3], speed = [1,1,1,1]
// Output: 1
// Explanation:
// At the start of minute 0, the distances of the monsters are [1,1,2,3], you eliminate the first monster.
// At the start of minute 1, the distances of the monsters are [X,0,1,2], so you lose.
// You can only eliminate 1 monster.
// Example 3:

// Input: dist = [3,2,4], speed = [5,3,2]
// Output: 1
// Explanation:
// At the start of minute 0, the distances of the monsters are [3,2,4], you eliminate the first monster.
// At the start of minute 1, the distances of the monsters are [X,0,2], so you lose.
// You can only eliminate 1 monster.

// Constraints:

// n == dist.length == speed.length
// 1 <= n <= 10^5
// 1 <= dist[i], speed[i] <= 10^5
// Testcase:
// [3,5,7,4,5]
// [2,3,6,3,2]
// [1,3,4]
// [1,1,1]
// [1,1,2,3]
// [1,1,1,1]
// [3,2,4]
// [5,3,2]
// [4,2,3]
// [2,1,1]
// [1]
// [1]
// [1]
// [5]
// Output:
// 2
// 3
// 1
// 1
// 3
// 1
// 1
// Runtime: 124 ms, faster than 25.00% of C++ online submissions for Eliminate Maximum Number of Monsters.
// Memory Usage: 83.1 MB, less than 50.00% of C++ online submissions for Eliminate Maximum Number of Monsters.

// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        auto sz = dist.size();

        vector<int> arrival_times(sz);
        for (auto i = 0; i < sz; i++)
        {
            arrival_times[i] = ceil(dist[i] / (speed[i] * 1.0));
        }

        // Ascending order of arrival times
        std::sort(arrival_times.begin(), arrival_times.end(), std::less<int>());

        auto cnt = 1;
        for (auto i = 1; i < sz; i++)
        {
            if (arrival_times[i] <= cnt)
            {
                break;
            }
            ++cnt;
        }
        return cnt;
    }
};

// Multiset based
// Runtime: 244 ms, faster than 25.00% of C++ online submissions for Eliminate Maximum Number of Monsters.
// Memory Usage: 111.2 MB, less than 50.00% of C++ online submissions for Eliminate Maximum Number of Monsters.
class SolutionMS
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        auto sz = dist.size();
        // Arrival times in ascending order
        std::multiset<int> at;

        vector<int> arrival_times(sz);
        for (auto i = 0; i < sz; i++)
        {
            at.emplace(ceil(dist[i] / (speed[i] * 1.0)));
        }

        auto cnt = 0;
        for (auto it = at.begin(); it != at.end(); ++it)
        {
            if (cnt && (*it <= cnt))
            {
                break;
            }
            ++cnt;
        }
        return cnt;
    }
};

// Priority queue based
// Runtime: 156 ms, faster than 25.00% of C++ online submissions for Eliminate Maximum Number of Monsters.
// Memory Usage: 85 MB, less than 50.00% of C++ online submissions for Eliminate Maximum Number of Monsters.
class SolutionPQ
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        auto sz = dist.size();
        // Arrival times in ascending order
        std::priority_queue<int, vector<int>, std::greater<int>> at;

        for (auto i = 0; i < sz; i++)
        {
            at.emplace(ceil(dist[i] / (speed[i] * 1.0)));
        }

        auto cnt = 0;
        while (cnt < sz)
        {
            if (at.top() <= cnt)
            {
                break;
            }
            at.pop();
            ++cnt;
        }
        return cnt;
    }
};