// You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.

// If it is possible, return any [i, j] with i + 1 < j, such that:

// arr[0], arr[1], ..., arr[i] is the first part,
// arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
// arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
// All three parts have equal binary values.
// If it is not possible, return [-1, -1].

// Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

// Example 1:

// Input: arr = [1,0,1,0,1]
// Output: [0,3]
// Example 2:

// Input: arr = [1,1,0,1,1]
// Output: [-1,-1]
// Example 3:

// Input: arr = [1,1,0,0,1]
// Output: [0,2]

// Constraints:

// 3 <= arr.length <= 3 * 10^4
// arr[i] is 0 or 1

// Testcase:
// [1,0,1,0,1]
// [1,1,0,0,1]
// [1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
// [1,1,0,0,1,1,1,1]
// [1,1,1]

// Output:
// [0,3]
// [0,2]
// [-1,-1]
// [1,6]
// [0,2]

// 118 / 118 test cases passed.
// Status: Accepted
// Runtime: 32 ms, 91.57%
// Memory Usage: 38.9 MB, 81.33%

// https://leetcode.com/problems/three-equal-parts/
// https://leetcode.com/problems/three-equal-parts/solution/

class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {

        auto ones = 0;
        std::for_each(arr.begin(), arr.end(), [&](int n)
                      { ones += n; });

        // All zero return 0,2
        if (ones == 0)
            return {0, 2};

        // Count of 1s not multiple of 3, then return -1,-1
        if (ones % 3)
            return {-1, -1};

        int sz = arr.size();

        // Try to divide into 3 parts
        int idx1 = -1, idx2 = -1, idx3 = -1, cnt = 0;
        for (int i = 0; i < sz; ++i)
        {
            cnt += arr[i];

            if ((idx1 == -1) && (cnt == 1))
            {
                idx1 = i;
            }

            if ((idx2 == -1) && (cnt == (ones / 3) + 1))
            {
                idx2 = i;
            }

            if ((idx3 == -1) && (cnt == (2 * ones / 3) + 1))
            {
                idx3 = i;
                break;
            }
        }

        //  Check if they could be divided
        for (int i = 0; i < sz - idx3; i++)
        {
            auto i1 = idx1 + i, i2 = idx2 + i, i3 = idx3 + i;
            if ((i1 >= idx2) || (i2 >= idx3) || (arr[i1] != arr[i2]) || (arr[i2] != arr[i3]))
            {
                // Not possible to divide
                return {-1, -1};
            }
        }

        return {idx1 + sz - 1 - idx3, idx2 + sz - idx3};
    }
};

// Another soluation, linear traversal
// Runtime: 40 ms, faster than 63.25% of C++ online submissions for Three Equal Parts.
// Memory Usage: 38.9 MB, less than 55.42% of C++ online submissions for Three Equal Parts.
class SolutionLS
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        auto ones = 0;
        std::for_each(arr.begin(), arr.end(), [&](int n)
                      { ones += n; });

        // All zero return 0,2
        if (ones == 0)
            return {0, 2};

        // Count of 1s not multiple of 3, then return -1,-1
        if (ones % 3)
            return {-1, -1};

        int sz = arr.size();

        // Check low, high and mid
        int partSize = ones / 3;

        auto findFirstOneInPart = [&](int pos)
        {
            int i = 0, k = 0;
            for (; i < sz && k != pos; i++)
            {
                k += arr[i];
            }
            return i;
        };

        // Find first set bit in part1, part2 and part3
        int left = findFirstOneInPart(1);
        int mid = findFirstOneInPart(partSize + 1);
        int right = findFirstOneInPart(2 * partSize + 1);

        // Check if all are same
        while (right < sz && arr[left] == arr[mid] && arr[mid] == arr[right])
        {
            left++;
            mid++;
            right++;
        }

        if (right != sz)
        {
            // Unequal values for parts
            return {-1, -1};
        }

        // Equal parts found, return the indexes
        return {left - 1, mid};
    }
};