// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

// Constraints:

// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.

// Follow up: Could you find an O(nums1.length + nums2.length) solution?

// Runtime: 8 ms, faster than 57.95% of C++ online submissions for Next Greater Element I.
// Memory Usage: 8.2 MB, less than 99.91% of C++ online submissions for Next Greater Element I.

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {
            // Get the equal element
            auto it1 = std::find(nums2.begin(), nums2.end(), nums1[i]);
            auto it2 = std::find_if(it1, nums2.end(), [&](int n)
                                    { return n > nums1[i]; });
            if (it2 != nums2.end())
            {
                result[i] = *it2;
            }
        }
        return result;
    }
};

// Using stack and a hashmap
// Runtime: 4 ms, faster than 94.93% of C++ online submissions for Next Greater Element I.
// Memory Usage: 8.9 MB, less than 56.44% of C++ online submissions for Next Greater Element I.
class Solution
{
public:
    // We use a stack to keep a decreasing sub-sequence, whenever we see a number x greater than stack.peek() we pop all elements less than x and for all the popped ones, their next greater element is x
    // For example [9, 8, 7, 3, 2, 1, 6]
    // The stack will first contain [9, 8, 7, 3, 2, 1] and then we see 6 which is greater than 1 so we pop 1 2 3 whose next greater element should be 6
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> nmap;
        stack<int> nstack;

        for (auto n : nums2)
        {
            while (!nstack.empty() && nstack.top() < n)
            {
                nmap.insert({nstack.top(), n});
                nstack.pop();
            }
            nstack.push(n);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            auto it = nmap.find(nums1[i]);
            if (it != nmap.end())
            {
                result[i] = it->second;
            }
        }
        return result;
    }
};