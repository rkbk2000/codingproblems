// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []

// Constraints:

// k == lists.length
// 0 <= k <= 10^4
// 0 <= lists[i].length <= 500
// -10^4 <= lists[i][j] <= 10^4
// lists[i] is sorted in ascending order.
// The sum of lists[i].length won't exceed 10^4.
// Accepted
// 916,118
// Submissions
// 2,093,565
// 133 / 133 test cases passed.
// Status: Accepted
// Runtime: 164 ms
// Memory Usage: 12.8 MB
// https://leetcode.com/problems/merge-k-sorted-lists/
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
// Simple method to iterate through each list and merge - Space O(1)
// time - each list, each list element (k) and comparison (logk)
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // TODO: Use recursion/minheap

        if (lists.empty())
        {
            return nullptr;
        }

        for (auto i = 1; i < lists.size(); ++i)
        {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }

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