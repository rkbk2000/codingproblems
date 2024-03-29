// https://leetcode.com/problems/split-linked-list-in-parts/

// 725. Split Linked List in Parts
// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

// Return an array of the k parts.

// Example 1:

// Input: head = [1,2,3], k = 5
// Output: [[1],[2],[3],[],[]]
// Explanation:
// The first element output[0] has output[0].val = 1, output[0].next = null.
// The last element output[4] is null, but its string representation as a ListNode is [].
// Example 2:

// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

// Constraints:

// The number of nodes in the list is in the range [0, 1000].
// 0 <= Node.val <= 1000
// 1 <= k <= 50

// Hint:
// If there are N nodes in the list, and k parts, then every part has N/k elements, except the first N%k parts have an extra one.

// Runtime: 8 ms, faster than 64.72% of C++ online submissions for Split Linked List in Parts.
// Memory Usage: 8.9 MB, less than 14.63% of C++ online submissions for Split Linked List in Parts.

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
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // find the length
        auto len = 0;
        auto temp = head;
        while (temp != nullptr)
        {
            ++len;
            temp = temp->next;
        }

        int extra = len % k;
        int size = len / k;

        vector<ListNode *> result;
        // First extra nodes will have size+1 nodes
        for (auto i = 0; i < k; i++)
        {
            ListNode *node = head, *prev = head;
            for (auto j = 0; j < size; j++)
            {
                prev = head;
                head = head->next;
            }
            if (i < extra)
            {
                prev = head;
                head = head->next;
            }
            if (prev)
                prev->next = nullptr;
            result.push_back(node);
        }
        return result;
    }
};