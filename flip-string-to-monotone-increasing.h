// https://leetcode.com/problems/flip-string-to-monotone-increasing/

// A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

// You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

// Return the minimum number of flips to make s monotone increasing.

// Example 1:

// Input: s = "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
// Example 2:

// Input: s = "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.
// Example 3:

// Input: s = "00011000"
// Output: 2
// Explanation: We flip to get 00000000.

// Constraints:

// 1 <= s.length <= 10^5
// s[i] is either '0' or '1'.

// Runtime: 24 ms, faster than 25.50% of C++ online submissions for Flip String to Monotone Increasing.
// Memory Usage: 11 MB, less than 24.25% of C++ online submissions for Flip String to Monotone Increasing.

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int flip0{0}, flip1{0};
        for (auto c : s)
        {
            // For every character, check the minimum number of flips required based on the current char
            switch (c)
            {
            case '0':
                flip1 = std::min(flip1, flip0) + 1;
                break;
            case '1':
                flip1 = std::min(flip1, flip0);
                flip0++;
                break;
            }
        }
        return std::min(flip0, flip1);
    }
};

// DP based approach
// IF ith character is 1 and i-1th character is 1 we use the same value
// Else we take the minimum of 1s till now or dp[i-1]+1
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int sz = s.size();
        vector<int> dp(sz + 1);
        int onecnt{s[0] - '0'};
        dp[0] = 0;

        for (int i = 1; i < sz; i++)
        {
            if (s[i] == '1')
            {
                ++onecnt;
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = std::min(onecnt, dp[i - 1] + 1);
            }
        }
        return dp[sz - 1];
    }
};

// Approach 1: Prefix Sums
// Intuition

// For say a 5 digit string, the answer is either '00000', '00001', '00011', '00111', '01111', or '11111'. Let's try to calculate the cost
//  of switching to that answer. The answer has two halves, a left (zero) half, and a right (one) half.
// Evidently, it comes down to a question of knowing, for each candidate half: how many ones are in the left half, and how many zeros are
// in the right half.
// We can use prefix sums. Say P[i+1] = A[0] + A[1] + ... + A[i], where A[i] = 1 if S[i] == '1', else A[i] = 0. We can calculate P in
// linear time.

// Then if we want x zeros followed by N-x ones, there are P[x] ones in the start that must be flipped, plus (N-x) - (P[N] - P[x]) zeros that must be flipped. The last calculation comes from the fact that there are P[N] - P[x] ones in the later segment of length N-x, but we want the number of zeros.

// Algorithm
// For example, with S = "010110": we have P = [0, 0, 1, 1, 2, 3, 3]. Now say we want to evaluate having x=3 zeros.
// There are P[3] = 1 ones in the first 3 characters, and P[6] - P[3] = 2 ones in the later N-x = 3 characters.
// So, there is (N-x) - (P[N] - P[x]) = 1 zero in the later N-x characters.
// We take the minimum among all candidate answers to arrive at the final answer.

// Runtime: 32 ms, faster than 18.88% of C++ online submissions for Flip String to Monotone Increasing.
// Memory Usage: 15.5 MB, less than 14.13% of C++ online submissions for Flip String to Monotone Increasing.
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int sz = s.size();
        vector<int> psum(sz + 1);
        psum[0] = 0;

        // Calculate the prefix sums
        for (int i = 0; i < sz; i++)
        {
            psum[i + 1] = psum[i] + s[i] - '0';
        }

        int result = INT_MAX;
        for (int i = 0; i <= sz; i++)
        {
            result = std::min(result, psum[i] + sz - i - (psum[sz] - psum[i]));
        }
        return result;
    }
};

// Concise solution
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int flip0 = 0, flip1 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            flip0 += s[i] - '0';
            flip1 = min(flip0, flip1 + (s[i] == '0'));
        }
        return flip1;
    }
};