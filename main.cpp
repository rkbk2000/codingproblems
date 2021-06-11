#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include <map>
#include <atomic>
#include <thread>
#include <algorithm>
#include <stdlib.h>
#include <coroutine>
#include "twosum.h"
#include "lladdtwonum.h"
#include "server_vs_tasks.h"

using namespace std;

enum class LogLevel
{
   eInfo = 1,
eDebug = 2,
eMax = 4
};

class RefTest
{
public:
   RefTest(const std::string& name) : name_(name) {}
   void Print()
   {
      std::cout << "In RefTest: " << name_ << std::endl;
   }
private:
   std::string name_;
};

RefTest& RetRef()
{
   static RefTest ret{""};
   return ret;
}

template<typename T>
void PrintType(T p1)
{
   //decltype(T) v1;
   // std::cout<<"Decl type is: "<< typeid(T).name;
}

std::atomic<int> global_counter(0);

void increase_global(int n) { for (int i = 0; i < n; ++i) ++global_counter; }


void SetLogLevelFromEnv()
{
   auto lglv = std::getenv("LOG_LEVEL");
   if (lglv) {
      std::string log_level{ std::getenv("LOG_LEVEL") };
      std::transform(log_level.begin(), log_level.end(), log_level.begin(),
         [](unsigned char c) { return std::toupper(c); });

      if (log_level == "DEBUG")
      {
         std::cout << "Debug" << std::endl;
      }
      else
      {
         std::cout << "Info" << std::endl;
      }
   }
}

void ChekArray()
{
   struct Metric
   {
      std::string name;
      std::string description;
   };

   Metric Debug_Metrics[] = { { "resp_time", "Response time for connect request in milliseconds" } };

   for (auto& m : Debug_Metrics) {
      std::cout << m.name << ":" << m.description << std::endl;
   }
}

void checkTwoSum() {
   twosum ts;
   std::vector<int> nums{ 2,7,11,15 };
   auto idxvals = ts.twoSum(nums, 9);
   ts.Print(idxvals);

   nums = { 3,3 };
   idxvals = ts.twoSum(nums, 6);
   ts.Print(idxvals);

   nums = { 0,2,3,3,5,7 };
   idxvals = ts.twoSum(nums, 6);
   ts.Print(idxvals);

   nums = { 1,3,4,2 };
   idxvals = ts.twoSum(nums, 6);
   ts.Print(idxvals);
}

int main(int argc, char** argv)
{
   /*auto v = iota();
   auto cnt = 0;

   auto print = [&]() { auto i = 0;  for (auto iter = v.begin(); iter != v.end(); ++iter) {
      std::cout << "Val: " << *(iter) << std::endl;
      ++i;
      if (i >= 4) {
         break;
      }
   }
   cnt += 4;
   };
   
   print();
   v = iota();
   std::cout << "Second:" << std::endl;
   print();*/

   auto& ref = RetRef();
   ref.Print();

   auto LogMetric = [&](const std::string& status, double elapsedTime) {
      ref.Print();
      std::cout << argc<<":" << status << ":" << elapsedTime << std::endl;
   };

   std::unique_ptr<RefTest> refPtr;
   refPtr = std::make_unique<RefTest>("v1");
   *refPtr = ref;

   refPtr->Print();

   std::map<std::string, std::reference_wrapper<RefTest>> families;
   families.emplace("v1", ref);

   for (auto& iter : families) {
      std::cout << iter.first << ":";
      iter.second.get().Print();
      std::cout<< std::endl;
   }
   std::ref(ref);

   PrintType(10);
   PrintType(10.5);
   LogMetric("success", 10);

   std::thread t;
   t = std::thread(increase_global, 1000);
   std::cout << "Value of global " << global_counter << std::endl;
   t.join();
   std::cout << "Value of global after " << global_counter << std::endl;

   SetLogLevelFromEnv();

   std::thread t1(ChekArray);   
   t1.join();

   checkTwoSum();

   auto getlist = [](std::vector<int> vals) {
      ListNode* head = nullptr, * prev = nullptr;
      for (auto v : vals) {
         ListNode* elem = new ListNode(v);
         if (head) {
            prev->next = elem;
         }
         else {
            head = elem;           
         }
         prev = elem;
      }
      return head;
   };

   LLAddTwoNum l1;
   auto res = l1.addTwoNumbers(getlist(std::vector<int>{2,4,3}), getlist(std::vector<int>{5, 6, 4}));
   l1.printRes(res);
   return 0;
}
