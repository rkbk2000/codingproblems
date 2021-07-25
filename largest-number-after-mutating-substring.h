// https://leetcode.com/problems/largest-number-after-mutating-substring/
// You are given a string num, which represents a large integer. You are also given a 0-indexed integer array change of length 10 that maps each digit 0-9 to another digit. More formally, digit d maps to digit change[d].

// You may choose to mutate any substring of num. To mutate a substring, replace each digit num[i] with the digit it maps to in change (i.e. replace num[i] with change[num[i]]).

// Return a string representing the largest possible integer after mutating (or choosing not to) any substring of num.

// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: num = "132", change = [9,8,5,0,3,6,4,2,6,8]
// Output: "832"
// Explanation: Replace the substring "1":
// - 1 maps to change[1] = 8.
// Thus, "132" becomes "832".
// "832" is the largest number that can be created, so return it.
// Example 2:

// Input: num = "021", change = [9,4,3,5,7,2,1,9,0,6]
// Output: "934"
// Explanation: Replace the substring "021":
// - 0 maps to change[0] = 9.
// - 2 maps to change[2] = 3.
// - 1 maps to change[1] = 4.
// Thus, "021" becomes "934".
// "934" is the largest number that can be created, so return it.
// Example 3:

// Input: num = "5", change = [1,4,7,5,3,2,5,6,9,4]
// Output: "5"
// Explanation: "5" is already the largest number that can be created, so return it.

// Constraints:

// 1 <= num.length <= 10^5
// num consists of only digits 0-9.
// change.length == 10
// 0 <= change[d] <= 9

// Should you change a digit if the new digit is smaller than the original?
// If changing the first digit and the last digit both make the number bigger, but you can only change one of them; which one should you change?
// Changing numbers closer to the front is always better

// Test case:
// "132"
// [9,8,5,0,3,6,4,2,6,8]
// "021"
// [9,4,3,5,7,2,1,9,0,6]
// "5"
// [1,4,7,5,3,2,5,6,9,4]
// "132"
// [9,8,7,9,3,6,4,2,6,8]
// "132"
// [9,8,7,0,3,6,4,2,6,8]
// "214010"
// [6,7,9,7,4,0,3,4,4,7]
// "334111"
// [0,9,2,3,3,2,5,5,5,5]
// "882911467866912"
// [5,1,7,7,8,5,2,8,9,2]
// "2144010"
// [6,7,9,7,4,0,3,4,4,7]

// Output:
// "832"
// "934"
// "5"
// "897"
// "832"
// "974676"
// "334999"
// "997911467866912"
// "9744676"

// Runtime: 76 ms, faster than 16.67% of C++ online submissions for Largest Number After Mutating Substring.
// Memory Usage: 28.7 MB, less than 33.33% of C++ online submissions for Largest Number After Mutating Substring.

class Solution
{
public:
    string maximumNumber(string num, vector<int> &change)
    {
        int prev = -1;
        for (int i = 0; i < num.size(); i++)
        {
            int d = num[i] - '0';
            if (change[d] < d)
            {
                // Ignore this character.
                if (prev != -1)
                {
                    break;
                }
                continue;
            }

            if (change[d] == d)
            {
                // We already have started a conversion, in between case
                if (prev != -1)
                {
                    prev = i;
                }
                continue;
            }

            if (prev == i - 1 || prev == -1)
            {
                num[i] = change[d] + '0';
                prev = i;
            }
            else
            {
                break;
            }
        }
        return num;
    }
};

// Better solution
// untime: 68 ms, faster than 16.67% of C++ online submissions for Largest Number After Mutating Substring.
// Memory Usage: 28.8 MB, less than 33.33% of C++ online submissions for Largest Number After Mutating Substring.
class Solution
{
public:
    string maximumNumber(string num, vector<int> &change)
    {
        bool mutated = false;

        for (int i = 0; i < num.size(); i++)
        {
            int d = num[i] - '0';
            auto c = change[d];
            if (c > d)
            {
                mutated = true;
                num[i] = c + '0';
            }
            else if (c < d && mutated)
            {
                break;
            }
        }
        return num;
    }
};