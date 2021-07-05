// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in
// the list's nodes (i.e., only nodes themselves may be changed.)

// Example 1:

// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

// Testcase:
// [1,2,3,4]
// []
// [1]
// [1,2,3,4,5]

// Output:
// [2,1,4,3]
// []
// [1]
// [2,1,4,3,5]
// Runtime: 4 ms, faster than 61.72% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.6 MB, less than 49.20% of C++ online submissions for Swap Nodes in Pairs.

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
    ListNode *swapPairs(ListNode *head)
    {
        auto cur = head;
        ListNode *prev = nullptr;

        while (cur != nullptr)
        {
            auto next = cur->next;
            if (next != nullptr)
            {
                // Swap cur and next
                cur->next = next->next;
                next->next = cur;
                if (prev != nullptr)
                {
                    prev->next = next;
                }
                else
                {
                    head = next;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                cur = next;
            }
        }
        return head;
    }
};

// Better solution using vectors
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.7 MB, less than 49.20% of C++ online submissions for Swap Nodes in Pairs.
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        auto cur = head;
        vector<ListNode *> list(101, nullptr);
        auto cnt = 0;

        // Convert into a array first, swap and rebuild the list
        while (cur != nullptr)
        {
            list[cnt++] = cur;
            cur = cur->next;
        }

        for (auto i = 1; i < cnt; i += 2)
        {
            std::swap(list[i - 1], list[i]);
        }

        for (auto i = 0; i < cnt; i++)
        {
            list[i]->next = list[i + 1];
        }

        return list[0];
    }
};