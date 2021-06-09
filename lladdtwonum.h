#pragma once

struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LLAddTwoNum {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* head = nullptr, *prev = nullptr;
      auto carry = 0;
      while (l1 && l2) {
         // next digit
         auto sum = (l1->val + l2->val + carry);

         // carry if any
         carry = sum / 10;

         auto elem = new ListNode(sum%10);
         if (head) {
            prev->next = elem;
         }
         else {
            // first element
            head = elem;            
         }
         prev = elem;
         l1 = l1->next;
         l2 = l2->next;
      }

      // Add the extra elemenets if any
      auto remList = (l1 != nullptr) ? l1 : l2;
      while (remList) {
         // next digit
         auto sum = (remList->val + carry);

         // carry if any
         carry = sum / 10;

         auto elem = new ListNode(sum % 10);
         if (head) {
            prev->next = elem;
         }
         else {
            // first element
            head = elem;
         }
         prev = elem;
         remList = remList->next;         
      }

      // Additional carry if any
      if (carry) {
         auto elem = new ListNode(carry);
         prev->next = elem;
      }
      return head;
   }
   
   void printRes(ListNode* l) {
      while (l) {
         std::cout << l->val << " ";
         l = l->next;
      }
      std::cout << "\n";
   }
};
