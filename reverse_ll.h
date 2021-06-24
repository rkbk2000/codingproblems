// Given the head of a singly linked list, reverse the list, and return the reversed list.
// Runtime: 8 ms, faster than 65.14% of C++ online submissions for Reverse Linked List.
// Memory Usage: 8.3 MB, less than 77.84% of C++ online submissions for Reverse Linked List.
// https://leetcode.com/problems/reverse-linked-list/submissions/
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *revList = nullptr;
        while (head != nullptr)
        {
            auto temp = head->next;
            head->next = revList;
            revList = head;
            head = temp;
        }
        return revList;
    }
};