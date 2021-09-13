// https://leetcode.com/problems/maximum-number-of-balloons/

// 1189. Maximum Number of Balloons
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

// Example 1:

// Input: text = "nlaebolko"
// Output: 1
// Example 2:

// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0

// Constraints:

// 1 <= text.length <= 10^4
// text consists of lower case English letters only.

// Hints:
// Count the frequency of letters in the given string.
// Find the letter than can make the minimum number of instances of the word "balloon".

// Runtime: 4 ms, faster than 75.55% of C++ online submissions for Maximum Number of Balloons.
// Memory Usage: 6.5 MB, less than 85.28% of C++ online submissions for Maximum Number of Balloons.

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> counts{{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for (auto c : text)
        {
            switch (c)
            {
            case 'b':
            case 'a':
            case 'l':
            case 'o':
            case 'n':
                counts[c]++;
                break;
            }
        }

        // At least a pair of chars needed for l and o
        counts['l'] = counts['l'] / 2;
        counts['o'] = counts['o'] / 2;

        int result = INT_MAX;
        for (auto &it : counts)
        {
            result = std::min(result, it.second);
        }
        return result;
    }
};

// Another
class Solution0ms
{
public:
    int maxNumberOfBalloons(string text)
    {
        int f[26];
        memset(f, 0, sizeof f);
        for (char c : text)
        {
            f[c - 'a']++;
        }
        int minn = INT_MAX;
        minn = min(minn, f['b' - 'a']);
        minn = min(minn, f['a' - 'a']);
        minn = min(minn, f['n' - 'a']);
        minn = min(minn, f['l' - 'a'] / 2);
        minn = min(minn, f['o' - 'a'] / 2);
        return minn;
    }
};