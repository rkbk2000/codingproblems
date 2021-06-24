
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from
// position left to position right, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 7.6 MB, less than 11.35% of C++ online submissions for Reverse Linked List II.
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
// https://leetcode.com/problems/reverse-linked-list-ii/
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        auto count = 1;
        auto temp = head;

        while (count != left)
        {
            temp = temp->next;
            ++count;
        }
        auto leftNode = temp;

        stack<int> nodes;
        while (count <= right)
        {
            nodes.push(temp->val);
            temp = temp->next;
            ++count;
        }

        while (!nodes.empty())
        {
            auto val = nodes.top();
            leftNode->val = val;
            nodes.pop();
            leftNode = leftNode->next;
        }
        return head;
    }
};

// Another version Space O(1)
// Runtime: 4 ms, faster than 60.08% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 7.4 MB, less than 91.62% of C++ online submissions for Reverse Linked List II.
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
class Solution1
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        auto count = 1;
        auto iter = head;
        ListNode *prevLeft = nullptr;

        while (count != left)
        {
            prevLeft = iter;
            iter = iter->next;
            ++count;
        }

        ListNode *temp = nullptr, *revHead = nullptr, *revTail = nullptr;

        while (count <= right)
        {
            temp = iter->next;
            iter->next = revHead;

            if (revHead == nullptr)
            {
                // Last node in the reversed list
                revTail = iter;
            }
            revHead = iter;

            iter = temp;
            ++count;
        }

        if (prevLeft != nullptr)
        {
            prevLeft->next = revHead;
        }
        else
        {
            head = revHead;
        }

        if (revTail != nullptr)
        {
            revTail->next = iter;
        }

        return head;
    }
};
