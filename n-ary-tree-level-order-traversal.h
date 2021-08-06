// Given an n-ary tree, return the level order traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

// Example 1:

// Input: root = [1,null,3,2,4,null,5,6]
// Output: [[1],[3,2,4],[5,6]]
// Example 2:

// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

// Constraints:

// The height of the n-ary tree is less than or equal to 1000
// The total number of nodes is between [0, 10^4]

// Testcase:
// [1,null,3,2,4,null,5,6]
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]

// Output:
// [[1],[3,2,4],[5,6]]
// [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

// Runtime: 24 ms, faster than 52.46% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 13.2 MB, less than 5.57% of C++ online submissions for N-ary Tree Level Order Traversal.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root != nullptr)
        {
            levelBFS(root);
        }
        return result;
    }

    void levelBFS(Node *root)
    {
        queue<Node *> myq;
        myq.push(root);

        while (true)
        {
            queue<Node *> tempq;
            vector<int> level;

            while (!myq.empty())
            {
                auto node = myq.front();
                level.push_back(node->val);
                for (auto child : node->children)
                {
                    tempq.push(child);
                }
                myq.pop();
            }
            result.push_back(level);
            if (tempq.empty())
            {
                break;
            }
            myq = tempq;
        }
    }
};

// Sample 8ms submission
class Solution8MS
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> q;
        vector<vector<int>> res;
        vector<int> tmp;
        if (root == NULL)
            return res;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node == NULL && !q.empty())
            {
                res.push_back(tmp);
                tmp.clear();
                q.push(NULL);
            }
            else if (node != NULL)
            {
                tmp.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++)
                {
                    q.push(node->children[i]);
                }
            }
            else
            {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};