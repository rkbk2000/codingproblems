// Runtime: 172 ms, faster than 92.85% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 114 MB, less than 80.26% of C++ online submissions for Palindrome Linked List.
// https://leetcode.com/problems/palindrome-linked-list/submissions/
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
    bool isPalindrome(ListNode *head)
    {
        // Use two pointers - slow and skipl - like we check for a loop in linked list
        // Slow moves as usual, skipl - > skips and moves
        // Reverse the skipl and compare each element until skipl is null.
        // If skipl is null, return true, false otehrwise.
        // One element extra if any in the slow will be automatically taken care (skipped)
        auto skipl = head, slow = head;
        while (skipl != nullptr && skipl->next != nullptr)
        {
            // Skip 1
            skipl = skipl->next->next;
            slow = slow->next;
        }

        skipl = nullptr;
        while (slow != nullptr)
        {
            auto t = slow->next;
            slow->next = skipl;
            skipl = slow;
            slow = t;
        }

        // Now skipl contains the second half of the list reversed
        // Now compare each element of right with element in the head
        while (skipl != nullptr)
        {
            if (head->val != skipl->val)
            {
                return false;
            }
            head = head->next;
            skipl = skipl->next;
        }
        // left is now pointing to mid element and right to the end element
        // Reverse the list from left->next to end of the list
        return true;
    }
};