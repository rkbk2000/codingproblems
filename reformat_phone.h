// https: //leetcode.com/problems/reformat-phone-number/
// You are given a phone number as a string number. number consists of digits, spaces ' ', and/or dashes '-'.

// You would like to reformat the phone number in a certain manner. Firstly, remove all spaces and dashes.
// Then, group the digits from left to right into blocks of length 3 until there are 4 or fewer digits. The final digits are then grouped as follows:

// 2 digits: A single block of length 2.
// 3 digits: A single block of length 3.
// 4 digits: Two blocks of length 2 each.
// The blocks are then joined by dashes. Notice that the reformatting process should never produce any blocks of length 1 and produce at most two blocks of length 2.

// Return the phone number after formatting.

// TBD
#include <algorithm>
#include <string>
class Solution
{
public:
    std::string reformatNumber(std::string number)
    {

        auto isSpaceOrDash = [](unsigned char c) -> bool
        {
            if (c == ' ' || c == '-')
                return true;
            return false;
        };
        // Remove space or a dash
        number.erase(remove_if(number.begin(), number.end(), isSpaceOrDash), number.end());

        auto len = number.size();
        auto result = number;
        auto cur = 2, nextPos = 3;
        while (cur < len)
        {
            if (cur % 3 == 0)
            {
                result.insert(nextPos, "-");
                nextPos += 4;
            }
            ++cur;
        }

        // Now check if we have only one last digit
        if (result[result.size() - 2] == '-')
        {
            result.erase(result.size() - 2, 1);
            result.insert(result.size() - 2, "-");
        }
        return result;
    }
};