// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end
// (the list is 1-indexed).

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]
// Example 3:

// Input: head = [1], k = 1
// Output: [1]
// Example 4:

// Input: head = [1,2], k = 1
// Output: [2,1]
// Example 5:

// Input: head = [1,2,3], k = 2
// Output: [1,2,3]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 10^5
// 0 <= Node.val <= 100
// Runtime: 548 ms, faster than 99.12% of C++ online submissions for Swapping Nodes in a Linked List.
// Memory Usage: 180 MB, less than 89.96% of C++ online submissions for Swapping Nodes in a Linked List.
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        auto cur = head;
        ListNode *right = nullptr, *left = nullptr;
        auto cnt = 1;

        for (; cur != nullptr; cur = cur->next)
        {
            if (right != nullptr)
            {
                right = right->next;
                continue;
            }

            if (cnt == k)
            {
                left = cur;
                right = head;
            }
            ++cnt;
        }

        // One nodes case
        if (left != right)
        {
            std::swap(left->val, right->val);
        }
        return head;
    }
};