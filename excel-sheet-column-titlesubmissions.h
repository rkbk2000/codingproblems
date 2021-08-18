// 168. Excel Sheet Column Title
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

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

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"
// Example 4:

// Input: columnNumber = 2147483647
// Output: "FXSHRXW"

// Testcase:
// 1
// 28
// 701
// 2147483647
// 52

// Output:
// "A"
// "AB"
// "ZY"
// "FXSHRXW"
// "AZ"

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
// Memory Usage: 6 MB, less than 42.59% of C++ online submissions for Excel Sheet Column Title.

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result;

        while (columnNumber > 0)
        {
            int d = columnNumber % 26;
            columnNumber /= 26;
            if (d == 0)
            {
                result += 'Z';
                // As we are doing a mod 26, Z will come as zero, hence decrease the value by 1
                --columnNumber;
            }
            else
            {
                result += 'A' + d - 1;
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};