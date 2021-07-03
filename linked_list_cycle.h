// Runtime: 12 ms, faster than 70.87% of C++ online submissions for Linked List Cycle.
// Memory Usage: 8.1 MB, less than 14.84% of C++ online submissions for Linked List Cycle.
// https://leetcode.com/problems/linked-list-cycle/submissions/
// O(1) space
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // O(1) space solution
        for (; head != nullptr; head = head->next)
        {
            if (head->val == INT_MAX)
            {
                return true;
            }
            head->val = INT_MAX;
        }
        return false;
    }
};

// Standard solution
// Runtime: 16 ms
// Memory Usage : 8.1 MB
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        auto slow = head, fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};