// Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

// A subtree of a node node is node plus every node that is a descendant of node.

// Example 1:

// Input: root = [1,null,0,0,1]
// Output: [1,null,0,null,1]
// Explanation:
// Only the red nodes satisfy the property "every subtree not containing a 1".
// The diagram on the right represents the answer.
// Example 2:

// Input: root = [1,0,1,0,0,0,1]
// Output: [1,null,1,null,1]
// Example 3:

// Input: root = [1,1,0,1,1,0,1,0]
// Output: [1,1,0,1,1,null,1]

// Constraints:

// The number of nodes in the tree is in the range [1, 200].
// Node.val is either 0 or 1.

// https://leetcode.com/problems/binary-tree-pruning/

// Test case:
// [1,null,0,0,1]
// [1,0,1,0,0,0,1]
// [1,1,0,1,1,0,1,0]
// [1,0,1,0,1,0,1]
// [1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1]
// [0,null,0,0,0]

// Expected:
// [1,null,0,null,1]
// [1,null,1,null,1]
// [1,1,0,1,1,null,1]
// [1,0,1,null,1,null,1]
// [1,1,0,1,1,0,1,0,1,null,1,null,1,null,1,1]
// []

// Runtime: 4 ms, faster than 59.89% of C++ online submissions for Binary Tree Pruning.
// Memory Usage: 9.6 MB, less than 10.75% of C++ online submissions for Binary Tree Pruning.

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
    TreeNode *pruneTree(TreeNode *root)
    {
        return prune(root);
    }

    TreeNode *prune(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        root->left = prune(root->left);
        root->right = prune(root->right);

        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
        }
        return root;
    }
};