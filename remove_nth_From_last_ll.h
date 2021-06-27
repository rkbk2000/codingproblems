// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

// Follow up: Could you do this in one pass?
// Hint: Maintain two pointers and update one with a delay of n steps.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 10.7 MB, less than 70.42% of C++ online submissions for Remove Nth Node From End of List.

// Test cases
// [1,2,3,4,5]
// 2
// [1]
// 1
// [1,2]
// 1
// [1,2,3]
// 3
// [1,2,3]
// 1

// Output:
// [1,2,3,5]
// []
// [1]
// [2,3]
// [1,2]

// https: //leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Option 1: find the length of the list l and then remove l-n-1th element
        // Second option : take two pointers - slow and fast with a length ok n+1 nodes

        if (head->next == nullptr)
        {
            // Single node
            return nullptr;
        }

        auto slow = head, fast = head;

        for (auto i = 1; i <= n; ++i)
        {
            fast = fast->next;
        }

        if (fast == nullptr)
        {
            // first element
            return head->next;
        }

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is now pointing to the previous node to be deleted
        slow->next = slow->next->next;

        return head;
    }
};