// 171. Excel Sheet Column Number
// Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28
// ...

// Example 1:

// Input: columnTitle = "A"
// Output: 1
// Example 2:

// Input: columnTitle = "AB"
// Output: 28
// Example 3:

// Input: columnTitle = "ZY"
// Output: 701
// Example 4:

// Input: columnTitle = "FXSHRXW"
// Output: 2147483647

// Constraints:

// 1 <= columnTitle.length <= 7
// columnTitle consists only of uppercase English letters.
// columnTitle is in the range ["A", "FXSHRXW"].

// Testcase:
// "A"
// "AB"
// "FXSHRXW"
// "ZY"
// "AA"
// "AZA"
// "AZ"

// Output:
// 1
// 28
// 2147483647
// 701
// 27
// 1353
// 52

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage: 6 MB, less than 63.78% of C++ online submissions for Excel Sheet Column Number.
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int p = 1, result = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--)
        {
            int d = (columnTitle[i] + 1 - 'A') % 26;
            if (d == 0)
                d = 26;
            result += d * p;
            p = (i > 0) ? p * 26 : p;
        }
        return result;
    }
};