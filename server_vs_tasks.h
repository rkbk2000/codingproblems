// Runtime: 408 ms, faster than 94.65% of C++ online submissions for Process Tasks Using Servers.
// Memory Usage: 119.9 MB, less than 84.43% of C++ online submissions for Process Tasks Using Servers.

// https://leetcode.com/problems/process-tasks-using-servers/
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Not working, check
class Solution
{
public:   
   vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
   {
      // weight vs index for fs and time vs index for bs
      typedef std::pair<int, int> pe;

      //  fs - list of free servers, bs-busy servers
      // bs contains elements according to available time
      std::priority_queue<pe, std::vector<pe>, std::greater<pe> > fs, bs;

      // Create a pq of next available time vs weight,index
      for (size_t idx = 0; idx < servers.size(); ++idx)
      {
         // Free servers contains elements weight wise
         fs.emplace(pe{ servers[idx], idx });
      }

      auto maxTasks = tasks.size();
      auto result = vector<int>(maxTasks);
      
      size_t taskIdx = 0, // Index of the task to be taken next, increment only if it is assigned to a server
          curTime = 0;    // curTime gets incremented by 1 or next available second every iteration

      while (taskIdx < maxTasks)
      {
         // Jump to the next available second
         if (fs.empty() && !bs.empty()) {
            curTime = bs.top().first;
         }

         // Remove the completed task(s)
         while (!bs.empty()) {
            auto& top = bs.top();
            if (top.first != curTime) {
               break;
            }
            fs.emplace(pe{ servers[top.second], top.second });
            bs.pop();            
         }

         // Assign all the available tasks upto current time
         while (!fs.empty() && (taskIdx <= curTime) && (taskIdx < maxTasks))
         {
            // First element will always be having lowest weight or lowest index if weights are same.
            auto server = fs.top();
            auto nextAvail = curTime + tasks[taskIdx];
            bs.emplace(pe{ nextAvail, {server.second} });
            result[taskIdx] = server.second;
            fs.pop();
            ++taskIdx;
         }
         ++curTime;
      }
      return result;
   }
};