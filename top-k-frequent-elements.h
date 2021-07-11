// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

// https: //leetcode.com/problems/top-k-frequent-elements/submissions/

// Runtime: 20 ms, faster than 32.94% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 13.5 MB, less than 89.38% of C++ online submissions for Top K Frequent Elements.

// https://leetcode.com/problems/top-k-frequent-elements/solution/
// Approach 1: Heap
// Let's start from the simple heap approach with O(Nlogk) time complexity. To ensure that O(Nlogk) is always less than \mathcal{O}(N \log N)O(NlogN), the particular case k = Nk=N could be considered separately and solved in \mathcal{O}(N)O(N) time.
// Approach 2: Quickselect (Hoare's selection algorithm)
// Quickselect is a textbook algorthm typically used to solve the problems "find kth something": kth smallest, kth largest, kth most frequent, kth less frequent, etc. Like quicksort, quickselect was developed by Tony Hoare, and also known as Hoare's selection algorithm.

// It has \mathcal{O}(N)O(N) average time complexity and widely used in practice. It worth to note that its worth case time complexity is \mathcal{O}(N^2)O(N
// 2
//  ), although the probability of this worst-case is negligible.

// The approach is the same as for quicksort.

// One chooses a pivot and defines its position in a sorted array in a linear time using so-called partition algorithm.

// As an output, we have an array where the pivot is on its perfect position in the ascending sorted array, sorted by the frequency. All elements on the left of the pivot are less frequent than the pivot, and all elements on the right are more frequent or have the same frequency.

// Hence the array is now split into two parts. If by chance our pivot element took N - kth final position, then kk elements on the right are these top kk frequent we're looking for. If not, we can choose one more pivot and place it in its perfect position.

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        std::unordered_map<int, int> countmap;
        for (auto &n : nums)
        {
            countmap[n]++;
        }

        // count , number
        typedef pair<int, int> countnum;
        std::priority_queue<countnum, vector<countnum>, std::less<countnum>> pq;
        for (auto &it : countmap)
        {
            pq.emplace(countnum{it.second, it.first});
        }

        vector<int> ans;
        for (auto i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
