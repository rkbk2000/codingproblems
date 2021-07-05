// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.

// Testcase :
// ["LRUCache","get","put","get","put","put","get","get"]
// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[1],[1]]

// Output
// [null,-1,null,-1,null,null,2,6]
// [null,null,null,1,null,-1,null,-1,3,4]
// [null,null,null,1,null,-1,null,-1,-1,-1]

// Runtime: 424 ms, faster than 26.49% of C++ online submissions for LRU Cache.
// Memory Usage: 174.1 MB, less than 22.50% of C++ online submissions for LRU Cache.

// https://leetcode.com/problems/lru-cache/submissions/
#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LRUCache22
{

   typedef list<pair<int, int>> value_list;

   // map of key versus iterator value, key
   unordered_map<int, value_list::iterator> cache;

   // List of values and used_count
   value_list values;

   int max_capacity;

public:
   LRUCache22(int capacity) : max_capacity{capacity}
   {
   }

   int get(int key)
   {
      auto it = cache.find(key);
      auto v = -1;
      if (it != cache.end())
      {
         auto u_node = it->second;
         if (u_node != values.begin())
         {
            values.emplace_front(u_node->first, key);
            cache[key] = values.begin();
            values.erase(u_node);
         }
         v = values.begin()->first;
      }
      return v;
   }

   void put(int key, int value)
   {
      auto it = cache.find(key);
      if (it != cache.end())
      {
         values.erase(it->second);
      }

      // Check for the size, remove last
      if (values.size() == max_capacity)
      {
         cache.erase(values.back().second);
         values.pop_back();
      }

      values.emplace_front(pair<int, int>{value, key});
      cache[key] = values.begin();
   }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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
// Test cases:
// ["LRUCache","get","put","get","put","put","get","get"]
// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[1],[1]]
// ["LRUCache","put","put","get","put","put","get"]
// [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
// ["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]
// [[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]

// Output:
// [null,-1,null,-1,null,null,2,6]
// [null,null,null,1,null,-1,null,-1,3,4]
// [null,null,null,1,null,-1,null,-1,-1,-1]
// [null,null,null,2,null,null,-1]
// [null,null,null,null,null,4,3,2,-1,null,-1,2,3,-1,5]

// Runtime: 376 ms, faster than 47.59% of C++ online submissions for LRU Cache.
// Memory Usage: 163.2 MB, less than 48.16% of C++ online submissions for LRU Cache.
class LRUCache
{

   struct ListNode
   {
      int val; // Value for the key
      int key; // Key to access the cache
      ListNode *next{nullptr};
      ListNode *prev{nullptr};
      ListNode(int k, int v) : key(k), val(v){};
      ListNode(int k, int v, ListNode *n, ListNode *p) : key(k), val(v), next(n), prev(p){};
   };

   // map of key versus iterator value, key
   unordered_map<int, ListNode *> cache;

   // List of values and used_count
   ListNode *head{nullptr}, *tail{nullptr};

   int max_capacity;

public:
   LRUCache(int capacity) : max_capacity{capacity}
   {
   }

   int get(int key)
   {
      auto it = cache.find(key);
      auto v = -1;

      if (it != cache.end())
      {
         // We are sure that there exists a node in our list
         update(it->second);
         cache[key] = head;
         v = head->val;
      }
      return v;
   }

   void put(int key, int value)
   {
      auto it = cache.find(key);
      ListNode *u_node{nullptr};
      if (it != cache.end())
      {
         // Existing node
         u_node = it->second;
         if (u_node == tail && u_node != head)
         {
            tail = u_node->prev;
         }
         u_node->val = value;
      }
      else if (cache.size() == max_capacity)
      {
         // Erase the last element
         u_node = tail;
         tail = u_node->prev;
         cache.erase(u_node->key);
         u_node->val = value;
         u_node->key = key;
      }

      if (u_node != nullptr)
      {
         update(u_node);
      }
      else
      {
         // New node
         u_node = new ListNode(key, value, head, nullptr);
         if (head == nullptr)
         {
            tail = u_node;
         }
         else
         {
            head->prev = u_node;
         }
         head = u_node;
      }
      cache[key] = head;
   }

   void update(ListNode *u_node)
   {
      if (u_node != head)
      {
         if (u_node == tail)
         {
            tail = u_node->prev;
         }
         auto temp = u_node->next;
         if (u_node->prev != nullptr)
         {
            u_node->prev->next = temp;
         }
         if (temp != nullptr)
         {
            temp->prev = u_node->prev;
         }
         u_node->prev = nullptr;
         u_node->next = head;
         head->prev = u_node;
         head = u_node;
      }
   }
};
