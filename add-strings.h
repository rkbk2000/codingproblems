// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"

// Constraints:

// 1 <= num1.length, num2.length <= 10^4
// num1 and num2 consist of only digits.
// num1 and num2 don't have any leading zeros except for the zero itself.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Strings.
// Memory Usage: 6.7 MB, less than 89.69% of C++ online submissions for Add Strings.

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int sz1 = num1.size(), sz2 = num2.size();

        //Always first string length would be <= second string length
        if (sz2 < sz1)
        {
            std::swap(num1, num2);
            std::swap(sz1, sz2);
        }

        int carry = 0;
        string ans{};

        auto add = [&](int sum)
        {
            carry = sum / 10;
            sum %= 10;
            ans += sum + '0';
        };

        //Always first string length would be <= second string length
        for (; sz1 > 0; sz1--, sz2--)
        {
            int s = (num1[sz1 - 1] - '0') + (num2[sz2 - 1] - '0') + carry;
            add(s);
        }

        for (; sz2 > 0; sz2--)
        {
            int s = num2[sz2 - 1] - '0' + carry;
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

class SolutionConcise
{
public:
    string addStrings(string num1, string num2)
    {
        int sz1 = num1.size(), sz2 = num2.size();

        int carry = 0;
        string ans{};

        //Always first string length would be <= second string length

        while (sz1 > 0 || sz2 > 0)
        {
            int d1{(sz1 > 0) ? (num1[sz1 - 1] - '0') : 0};
            --sz1;
            int d2{(sz2 > 0) ? (num2[sz2 - 1] - '0') : 0};
            --sz2;

            int sum = d1 + d2 + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
        }

        if (carry)
            ans += '1';

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};