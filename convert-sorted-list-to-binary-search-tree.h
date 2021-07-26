// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example 1:

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [0]
// Output: [0]
// Example 4:

// Input: head = [1,3]
// Output: [3,1]

// Constraints:

// The number of nodes in head is in the range [0, 2 * 10^4].
// -10^5 <= Node.val <= 10^5

// Runtime: 32 ms, faster than 54.71% of C++ online submissions for Convert Sorted List to Binary Search Tree.
// Memory Usage: 31.3 MB, less than 18.86% of C++ online submissions for Convert Sorted List to Binary Search Tree.

// Testcase:
// [-10,-3,0,5,9]
// []
// [0]
// [1,3]

// Output:
// [0,-10,5,null,-3,null,9]
// []
// [0]
// [1,null,3]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> nums;
        while (head != nullptr)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }
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