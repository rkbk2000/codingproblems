// Test case:
// "loveleetcode"
// "e"
// "loveleetcodegab"
// "e"
// "eloveleetcodegab"
// "e"
// "e"
// "e"
// "eloveabc"
// "e"
// "loveabcd"
// "d"
// "dloveabc"
// "d"

// Output:
// [3,2,1,0,1,0,0,1,2,2,1,0]
// [3,2,1,0,1,0,0,1,2,2,1,0,1,2,3]
// [0,1,2,1,0,1,0,0,1,2,2,1,0,1,2,3]
// [0]
// [0,1,2,1,0,1,2,3]
// [7,6,5,4,3,2,1,0]
// [0,1,2,3,4,5,6,7]

// Runtime: 4 ms, faster than 66.09% of C++ online submissions for Shortest Distance to a Character.
// Memory Usage: 6.8 MB, less than 46.21% of C++ online submissions for Shortest Distance to a Character.

// https://leetcode.com/problems/shortest-distance-to-a-character/submissions/

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        auto size = s.size();
        vector<int> answer(size);

        auto prev = INT_MIN + (int)pow(10, 4), ansIdx = 0;
        auto pos = s.find(c);

        while (pos != string::npos)
        {
            for (; ansIdx < pos; ++ansIdx)
            {
                answer[ansIdx] = min(int(pos) - ansIdx, ansIdx - prev);
            }
            prev = pos;
            ansIdx = pos + 1;
            pos = s.find(c, pos + 1);
        }

        // Remnants if any
        for (auto i = ansIdx; i < size; ++i)
        {
            answer[i] = i - ansIdx + 1;
        }
        return answer;
    }
};

// Another solution - recommended by LC, on par with previous
// Runtime: 4 ms, faster than 66.09% of C++ online submissions for Shortest Distance to a Character.
// Memory Usage: 6.7 MB, less than 46.21% of C++ online submissions for Shortest Distance to a Character.
class Solution2
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        auto size = s.size();
        vector<int> answer(size);

        auto prev = INT_MIN >> 2;

        // Forward pass
        for (auto i = 0; i < size; ++i)
        {
            if (s[i] == c)
            {
                prev = i;
            }
            answer[i] = i - prev;
        }

        prev = INT_MAX >> 2;
        // Reverse pass
        for (int i = size - 1; i >= 0; --i)
        {
            if (s[i] == c)
            {
                prev = i;
            }
            answer[i] = min(answer[i], prev - i);
        }
        return answer;
    }
};