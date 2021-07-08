// Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
// Since the answer may be too large, return it modulo 10^9 + 7.

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
// Example 2:

// Input: n = 2
// Output: 10
// Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
// Example 3:

// Input: n = 5
// Output: 68

// Constraints:

// 1 <= n <= 2 * 10^4

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Vowels Permutation.
// Memory Usage: 5.8 MB, less than 99.84% of C++ online submissions for Count Vowels Permutation.

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        int64_t aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        int MOD = 1000000007;

        for (int i = 1; i < n; i++)
        {
            int64_t aCur = (eCount + iCount + uCount) % MOD;
            int64_t eCur = (aCount + iCount) % MOD;
            int64_t iCur = (eCount + oCount) % MOD;
            int64_t oCur = (iCount) % MOD;
            int64_t uCur = (iCount + oCount) % MOD;
            aCount = aCur;
            eCount = eCur;
            iCount = iCur;
            oCount = oCur;
            uCount = uCur;
        }
        int64_t result = (aCount + eCount + iCount + oCount + uCount) % MOD;
        return (int)result;
    }
};