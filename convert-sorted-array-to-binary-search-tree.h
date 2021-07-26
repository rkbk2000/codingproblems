
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

// Constraints:

// 1 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// nums is sorted in a strictly increasing order.

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Testcase
// [-10,-3,0,5,9]
// [1,3]

// output:
// [0,-10,5,null,-3,null,9]
// [1,null,3]

// Runtime: 12 ms, faster than 76.12% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 21.4 MB, less than 42.84% of C++ online submissions for Convert Sorted Array to Binary Search Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return arrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *arrayToBST(const vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid], arrayToBST(nums, start, mid - 1), arrayToBST(nums, mid + 1, end));
        return root;
    }
};