
// There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

// For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
// When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

// You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

// Return the chair number that the friend numbered targetFriend will sit on.

// Example 1:

// Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
// Output: 1
// Explanation:
// - Friend 0 arrives at time 1 and sits on chair 0.
// - Friend 1 arrives at time 2 and sits on chair 1.
// - Friend 1 leaves at time 3 and chair 1 becomes empty.
// - Friend 0 leaves at time 4 and chair 0 becomes empty.
// - Friend 2 arrives at time 4 and sits on chair 0.
// Since friend 1 sat on chair 1, we return 1.
// Example 2:

// Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
// Output: 2
// Explanation:
// - Friend 1 arrives at time 1 and sits on chair 0.
// - Friend 2 arrives at time 2 and sits on chair 1.
// - Friend 0 arrives at time 3 and sits on chair 2.
// - Friend 1 leaves at time 5 and chair 0 becomes empty.
// - Friend 2 leaves at time 6 and chair 1 becomes empty.
// - Friend 0 leaves at time 10 and chair 2 becomes empty.
// Since friend 0 sat on chair 2, we return 2.

// Constraints:

// n == times.length
// 2 <= n <= 10^4
// times[i].length == 2
// 1 <= arrivali < leavingi <= 10^5
// 0 <= targetFriend <= n - 1
// Each arrivali time is distinct.

// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

// Test case:
// [[1,4],[2,3],[4,6]]
// 1
// [[3,10],[1,5],[2,6]]
// 0
// [[3,10],[1,2],[2,6]]
// 0
// [[1,4],[2,3],[4,6]]
// 0
// [[33889,98676],[80071,89737],[44118,52565],[52992,84310],[78492,88209],[21695,67063],[84622,95452],[98048,98856],[98411,99433],[55333,56548],[65375,88566],[55011,62821],[48548,48656],[87396,94825],[55273,81868],[75629,91467]]
// 6

// Output:
// 1
// 2
// 1
// 0
// 2

// solution 1
// runtime - 1592 ms - rute force - O (n^3)
class Solution1592
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        // Map of times versus chair index
        map<pair<int, int>, int> chairmap;

        for (auto i = 0; i < times.size(); i++)
        {
            auto &row = times[i];
            chairmap.emplace(pair{row[0], row[1]}, i);
        }

        vector<int> occupied;
        int count = 0, index = 0;
        for (auto it = chairmap.begin(); it != chairmap.end(); ++it)
        {
            int start = it->first.first;
            auto found = false;
            for (auto j = 0; j < occupied.size(); j++)
            {
                if (occupied[j] <= start)
                {
                    occupied[j] = it->first.second;
                    found = true;
                    index = j;
                    break;
                }
            }
            if (!found)
            {
                index = count;
                occupied.push_back(it->first.second);
                count++;
            }
            if (it->first.first == times[targetFriend][0])
            {
                return index;
            }
        }
        return 0;
    }
};

// Improved version - still not good
// Runtime: 208 ms, faster than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
// Memory Usage: 68.5 MB, less than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair
class Solution208
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        // Arrival time vs leaving time in sorted order
        set<pair<int, int>> friends;

        // Sort by arrival time
        for (auto i = 0; i < times.size(); i++)
        {
            auto &row = times[i];
            friends.emplace(pair{row[0], row[1]});
        }

        // Ascending order by available time, chair number
        set<pair<int, int>> occupied;
        for (auto it = friends.begin(); it != friends.end(); ++it)
        {
            int arrival = it->first;
            int chair = occupied.size();

            if (!occupied.empty())
            {
                auto sit = occupied.begin();
                auto minit = it;
                auto found = false;
                while (sit->first <= arrival && sit != occupied.end())
                {
                    if (sit->second < chair)
                    {
                        chair = sit->second;
                        minit = sit;
                        found = true;
                    }
                    ++sit;
                }
                if (found)
                {
                    occupied.erase(minit);
                }
            }

            occupied.emplace(pair{it->second, chair});

            if (arrival == times[targetFriend][0])
            {
                return chair;
            }
        }
        return 0;
    }
};

// USing a set
// Runtime: 1620 ms, faster than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
// Memory Usage: 60.3 MB, less than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
class Solution1620
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {

        auto tftime = times[targetFriend][0];
        std::sort(times.begin(), times.end());

        // Ascending order by available time, chair number
        set<pair<int, int>> occupied; // Occupied chairs ordered by time
        set<int> avail;               // Available chairs for the next guest ordered by chair number

        for (auto &time : times)
        {
            int arrival = time[0];

            // Collect all free chairs
            for (auto &it : occupied)
            {
                if (it.first <= arrival)
                {
                    avail.emplace(it.second);
                    occupied.erase(it);
                }
            }

            // Chair to be occupied
            int chair = occupied.size();
            if (!avail.empty())
            {
                chair = *avail.begin();
                avail.erase(avail.begin());
            }

            if (arrival == tftime)
            {
                return chair;
            }
            occupied.emplace(time[1], chair);
        }
        return -1;
    }
};

// Using two Priority queues
// Runtime: 180 ms, faster than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
// Memory Usage: 50.9 MB, less than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
class Solution180
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {

        auto tftime = times[targetFriend][0];
        std::sort(times.begin(), times.end());

        // Occupied chairs ordered by time
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> occupied;

        // Available chairs for the next guest ordered by chair number
        priority_queue<int, vector<int>, std::greater<int>> avail;

        for (auto &time : times)
        {
            int arrival = time[0];

            // Collect all free chairs
            while (!occupied.empty() && occupied.top().first <= arrival)
            {
                avail.push(occupied.top().second);
                occupied.pop();
            }

            // Chair to be occupied
            int chair = occupied.size();
            if (!avail.empty())
            {
                chair = avail.top();
                avail.pop();
            }

            if (arrival == tftime)
            {
                return chair;
            }
            occupied.push(pair{time[1], chair});
        }
        return -1;
    }
};