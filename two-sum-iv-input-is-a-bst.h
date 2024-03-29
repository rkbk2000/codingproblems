// 653. Two Sum IV - Input is a BST
// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:

// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:

// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
// Example 3:

// Input: root = [2,1,3], k = 4
// Output: true
// Example 4:

// Input: root = [2,1,3], k = 1
// Output: false
// Example 5:

// Input: root = [2,1,3], k = 3
// Output: true

// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// -10^4 <= Node.val <= 10^4
// root is guaranteed to be a valid binary search tree.
// -10^5 <= k <= 10^5

// Runtime: 56 ms, faster than 16.68% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 42.8 MB, less than 5.23% of C++ online submissions for Two Sum IV - Input is a BST.

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
    unordered_multiset<int> vals;

public:
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);
        return twosum(k);
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        vals.insert(root->val);
        inorder(root->right);
    }

    bool twosum(int k)
    {
        for (auto n1 : vals)
        {
            auto n2 = k - n1;
            int expected = (n1 == n2) ? 2 : 1;
            if (vals.count(n2) >= expected)
            {
                return true;
            }
        }
        return false;
    }
};

// binary search version
// Runtime: 36 ms, faster than 77.57% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 36.8 MB, less than 67.55% of C++ online submissions for Two Sum IV - Input is a BST.
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
class SolutionBS
{
    // Ordered vector of values
    vector<int> vals;

public:
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);
        return twosum(k);
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    bool twosum(int k)
    {
        // Using binary search
        int i = 0, j = vals.size() - 1;

        while (i < j)
        {
            auto sum = vals[i] + vals[j];
            if (sum == k)
            {
                return true;
            }
            if (sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};