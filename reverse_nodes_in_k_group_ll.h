// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
// Example 3:

// Input: head = [1,2,3,4,5], k = 1
// Output: [1,2,3,4,5]
// Example 4:

// Input: head = [1], k = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is in the range sz.
// 1 <= sz <= 5000
// 0 <= Node.val <= 1000
// 1 <= k <= sz

// TODO: Follow-up: Can you solve the problem in O(1) extra memory space?

// Test case:
// [1,2,3,4,5]
// 2
// [1,2,3,4,5]
// 3
// [1,2,3,4,5]
// 1
// [1]
// 1

// Output
// [2,1,4,3,5]
// [3,2,1,4,5]
// [1,2,3,4,5]
// [1]

// Runtime: 8 ms, faster than 99.25% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 11.5 MB, less than 26.21% of C++ online submissions for Reverse Nodes in k-Group.
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int cnt = 1;
        auto cur = head, left = head;
        ListNode *prev = nullptr;

        while (cur != nullptr)
        {
            if ((cnt % k) == 0)
            {
                // Reverse, right
                auto right = cur != nullptr ? cur->next : nullptr; // Exclude right
                auto temp = reverseBetween(left, right);
                if (prev == nullptr)
                {
                    head = temp;
                }
                else
                {
                    prev->next = temp;
                }
                prev = left;
                cur = left;
                left = right;
            }
            cur = cur->next;
            ++cnt;
        }
        return head;
    }

    ListNode *reverseBetween(ListNode *left, ListNode *right)
    {
        auto cur = left;
        ListNode *revHead = nullptr;

        while (cur != right)
        {
            auto temp = cur->next;
            cur->next = revHead;
            revHead = cur;
            cur = temp;
        }

        // Link to the remaining list
        left->next = right;
        return revHead;
    }
};
