// Given two binary strings a and b, return their sum as a binary string.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

// Constraints:

// 1 <= a.length, b.length <= 10^4
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

// Testcase:
// "11"
// "1"
// "1010"
// "1011"
// "100"
// "110010"
// "110010"
// "100"

// Output:
// "100"
// "10101"
// "110110"
// "110110"
// https://leetcode.com/problems/add-binary/

// Runtime: 4 ms, faster than 67.94% of C++ online submissions for Add Binary.
// Memory Usage: 7 MB, less than 27.03% of C++ online submissions for Add Binary.
class Solution
{
public:
    string addBinary(string a, string b)
    {

        int alen = a.size(), blen = b.size();

        if (blen < alen)
        {
            std::swap(a, b);
            std::swap(alen, blen);
        }

        int carry = 0;
        string ans{};

        auto add = [&](int sum)
        {
            if (sum > 1)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            sum %= 2;
            char c = sum + '0';
            ans = c + ans;
        };

        //Always first string length would be <= second string length
        for (; alen > 0; alen--, blen--)
        {
            int s = (a[alen - 1] - '0') + (b[blen - 1] - '0') + carry;
            add(s);
        }

        for (; blen > 0; blen--)
        {
            int s = b[blen - 1] - '0' + carry;
            add(s);
        }

        if (carry)
        {
            ans = '1' + ans;
        }
        return ans;
    }
};

// Another solution
// Runtime: 4 ms, faster than 67.94% of C++ online submissions for Add Binary.
// Memory Usage: 6.2 MB, less than 95.74% of C++ online submissions for Add Binary.
class Solution
{
public:
    string addBinary(string a, string b)
    {

        int alen = a.size(), blen = b.size();

        if (blen < alen)
        {
            std::swap(a, b);
            std::swap(alen, blen);
        }

        int carry = 0;
        string ans{};

        auto add = [&](int sum)
        {
            if (sum > 1)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            sum %= 2;
            ans += sum + '0';
        };

        //Always first string length would be <= second string length
        for (; alen > 0; alen--, blen--)
        {
            int s = (a[alen - 1] - '0') + (b[blen - 1] - '0') + carry;
            add(s);
        }

        for (; blen > 0; blen--)
        {
            int s = b[blen - 1] - '0' + carry;
            add(s);
        }

        if (carry)
        {
            ans += '1';
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};