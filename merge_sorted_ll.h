// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first
// two lists.

// Example 1:

// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: l1 = [], l2 = []
// Output: []
// Example 3:

// Input: l1 = [], l2 = [0]
// Output: [0]

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both l1 and l2 are sorted in non-decreasing order.
// // Runtime: 8 ms, faster than 75.02% of C++ online submissions for Merge Two Sorted Lists.
// // Memory Usage: 14.8 MB, less than 86.95% of C++ online submissions for Merge Two Sorted Lists.

// // https://leetcode.com/problems/merge-two-sorted-lists/submissions/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        // check for zero length lists
        if (l1 == nullptr)
        {
            return l2;
        }

        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode *head = nullptr, *iter = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            ListNode *temp = nullptr;
            if (l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp = l2;
                l2 = l2->next;
            }

            if (head == nullptr)
            {
                head = temp;
                iter = temp;
            }
            iter->next = temp;
            iter = temp;
        }

        // Link the remnant nodes if any
        if (l1 != nullptr)
        {
            iter->next = l1;
        }
        else if (l2 != nullptr)
        {
            iter->next = l2;
        }
        return head;
    }
};