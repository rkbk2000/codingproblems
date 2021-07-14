// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:

// Input: p = [1,2,3], q = [1,2,3]
// Output: true
// Example 2:

// Input: p = [1,2], q = [1,null,2]
// Output: false
// Example 3:

// Input: p = [1,2,1], q = [1,1,2]
// Output: false

// Constraints:

// The number of nodes in both trees is in the range [0, 100].
// -10^4 <= Node.val <= 10^4

// Test cases:
// [1,2,3]
// [1,2,3]
// [1,2]
// [1,null,2]
// [1,2,1]
// [1,1,2]

// Output:
// true
// false
// false

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
// Memory Usage: 10 MB, less than 41.43% of C++ online submissions for Same Tree.

// https://leetcode.com/problems/same-tree/submissions/

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        return checkequal(p, q);
    }

    bool checkequal(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr and q == nullptr)
        {
            return true;
        }

        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return checkequal(p->left, q->left) && checkequal(p->right, q->right);
    }
};

// https://leetcode.com/problems/same-tree/solution/