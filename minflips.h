// For the 1st operation, we can simply do s += s to append the whole string to the end.
// then we make two different string with the same length by 01 and 10 alternative. for example: s = 11100
// s = 1110011100
// str1= 1010101010
// str2= 0101010101
// finally, use sliding window（size n）to compare s to both str1 and str2.
// why we can double s to fullfil the first operation, let's look at the same example s = 11100:`
// double s: 1110011100
// size n window: |11100|11100 ==> 1|11001|1100 ==> 11|10011|100 and so on, when we move one step of the sliding window,
// it is the same to append 1 more element from beginning.
// Time complexity
// Time O(N)
// Space O(N) ==> O(1)
// Solution
// C++, O(N) space is easier to understand.
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
class Solution1
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        s += s;
        string str1, str2;

        for (int i = 0; i < s.size(); i++)
        {
            str1 += i % 2 ? '0' : '1';
            str2 += i % 2 ? '1' : '0';
        }
        int anstr1 = 0, anstr2 = 0, ans = INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            if (str1[i] != s[i])
                ++anstr1;
            if (str2[i] != s[i])
                ++anstr2;
            if (i >= n)
            {
                //the most left element is outside of sliding window, we need to subtract the ans if we did `flip` before.
                if (str1[i - n] != s[i - n])
                    --anstr1;
                if (str2[i - n] != s[i - n])
                    --anstr2;
            }
            if (i >= n - 1)
                ans = min({anstr1, anstr2, ans});
        }
        return ans;
    }
};

// O(1) space based solution

class Solution2
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        int anstr1 = 0, anstr2 = 0, ans = INT_MAX;
        for (int i = 0; i < 2 * n; i++)
        {
            if (i < n)
                s[i] -= '0'; //make '1' and '0' to be integer 1 and 0.
            if (i % 2 != s[i % n])
                ++anstr1;
            if ((i + 1) % 2 != s[i % n])
                ++anstr2;
            if (i >= n)
            {
                if ((i - n) % 2 != s[i - n])
                    --anstr1;
                if ((i - n + 1) % 2 != s[i - n])
                    --anstr2;
            }
            if (i >= n - 1)
                ans = min({anstr1, anstr2, ans});
        }
        return ans;
    }
};