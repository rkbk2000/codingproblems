// https://leetcode.com/problems/path-sum-ii/

// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

// A leaf is a node with no children.

// Example 1:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Example 2:

// Input: root = [1,2,3], targetSum = 5
// Output: []
// Example 3:

// Input: root = [1,2], targetSum = 0
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

// Testcase:
// [5,4,8,11,null,13,4,7,2,null,null,5,1]
// 22
// [1,2,3]
// 5
// [1,2]
// 0
// [1,2]
// 1
// [2,1,3]
// 3
// [1,2,3,4]
// 3

// Output:
// [[5,4,11,2],[5,8,4,5]]
// []
// []
// []
// [[2,1]]
// []

// Using recursion
// Runtime: 8 ms, faster than 81.38% of C++ online submissions for Path Sum II.
// Memory Usage: 20.1 MB, less than 51.10% of C++ online submissions for Path Sum II.

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
    vector<vector<int>> result;
    vector<int> path;
    int sum{0};

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        backtrack(root, targetSum);
        return result;
    }

    void backtrack(TreeNode *root, int targetSum)
    {

        if (root == nullptr)
        {
            return;
        }
        path.push_back(root->val);
        sum += root->val;

        backtrack(root->left, targetSum);  // Left
        backtrack(root->right, targetSum); // Right

        if (sum == targetSum && root->right == nullptr && root->left == nullptr)
        {
            result.push_back(path); // Include
        }

        if (!path.empty())
        { // Exclude
            sum -= path.back();
            path.pop_back();
        }
    }
};

// Runtime: 8 ms, faster than 81.38% of C++ online submissions for Path Sum II.
// Memory Usage: 19.9 MB, less than 61.28% of C++ online submissions for Path Sum II.
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
class SolutionConcise
{
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        backtrack(root, targetSum, 0);
        return result;
    }

    void backtrack(TreeNode *root, int targetSum, int currSum)
    {

        if (root == nullptr)
        {
            return;
        }
        path.push_back(root->val);
        currSum += root->val;

        if (currSum == targetSum && root->right == nullptr && root->left == nullptr)
        {                           // Leaf node
            result.push_back(path); // Include
        }
        else
        {
            backtrack(root->left, targetSum, currSum);  // Left
            backtrack(root->right, targetSum, currSum); // Right
        }
        path.pop_back(); // Exclude
    }
};