#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <iostream>

class twosum
{
public:
   std::vector<int> twoSumOn(std::vector<int>& nums, int target) {      
      std::unordered_multimap<int, int> idxvals;
      auto idx = 0;
      std::transform(nums.begin(), nums.end(), std::inserter(idxvals, idxvals.end()),
         [&](int k) { return std::make_pair(k, idx++); });
      
      for (idx = 0; idx < (int) nums.size(); ++idx) {
         auto num1 = nums[idx];
         auto num2 = target - num1;
         auto iter = idxvals.find(num2);
         
         if (iter == idxvals.end()) {
            continue;
         }

         if (iter->second < idx) {
            continue;
         }

         if (iter->second == idx) {
            // A condition where same number is repeated - For e.g. 3,3 and target 6
            // Map will not work in this case
            ++iter;
            if (iter != idxvals.end() && iter->first != num2) {
               continue;
            }
         }
         if (iter != idxvals.end()) {
            return std::vector<int> {idx, iter->second};
         }

      // Duplicate the vector
      // Sort it
      // For each element, run find
      }
    
      return std::vector<int>{-1,-1};
   }
   
   std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_multimap<int, int> idxvals;
      std::vector<int> result((size_t)2);

      for (auto idx = 0; idx < (int)nums.size(); ++idx) {
         auto num1 = nums[idx];
         auto num2 = target - num1;
         auto iter = idxvals.find(num2);

         if (iter == idxvals.end()) {
            idxvals.emplace(num1, idx);
            continue;
         }
         result = {iter->second, idx};
         return result;
      }

      return std::vector<int>{-1, -1};
   }

  /* void Print(std::unordered_multimap<int, int> idxvals) {
      std::for_each(idxvals.begin(), idxvals.end(),
         [](std::pair<const int, int>& pair) { std::cout << pair.first << ":" << pair.second << "\n"; });
   }*/

   void Print(std::vector<int>& idxvals) {
      std::for_each(idxvals.begin(), idxvals.end(), [](const int v) { std::cout << v << " "; });
      std::cout << "\n";
   }
};

