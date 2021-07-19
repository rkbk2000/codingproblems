// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example 1:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
// Example 2:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
// Example 3:

// Input: root = [2,1], p = 2, q = 1
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the BST.

// Testcase:
// [6,2,8,0,4,7,9,null,null,3,5]
// 2
// 8
// [6,2,8,0,4,7,9,null,null,3,5]
// 2
// 4
// [2,1]
// 2
// 1

// Output:
// 6
// 2
// 2

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// 27 / 27 test cases passed.
// Status: Accepted
// Runtime: 24 ms, 95.1%
// Memory Usage: 23.3 MB, 57.6%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val > q->val)
        {
            std::swap(p, q);
        }
        TreeNode *lca = root;

        while (lca != nullptr)
        {
            if (p->val == lca->val || q->val == lca->val)
            {
                break;
            }

            if (p->val < lca->val && q->val > lca->val)
            {
                break;
            }

            if (p->val > lca->val)
            {
                // Inspect the right subtree
                lca = lca->right;
            }
            else if (p->val < lca->val)
            {
                // Inspect left
                lca = lca->left;
            }
        }
        return lca;
    }
};

// Another solution:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Runtime: 28 ms, faster than 79.85% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 23.2 MB, less than 57.60% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.

class Solution1
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // if (p->val > q->val) { std::swap(p,q);}
        TreeNode *lca = root;

        while (true)
        {
            if (p->val > lca->val && q->val > lca->val)
            {
                // Inspect the right subtree
                lca = lca->right;
            }
            else if (p->val < lca->val && q->val < lca->val)
            {
                // Inspect left
                lca = lca->left;
            }
            else
            {
                break;
            }
        }
        return lca;
    }
};