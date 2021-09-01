// https://leetcode.com/problems/array-nesting/
// 565. Array Nesting
// You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

// You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

// The first element in s[k] starts with the selection of the element nums[k] of index = k.
// The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
// We stop adding right before a duplicate element occurs in s[k].
// Return the longest length of a set s[k].

// Example 1:

// Input: nums = [5,4,0,3,1,6,2]
// Output: 4
// Explanation:
// nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
// One of the longest sets s[k]:
// s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
// Example 2:

// Input: nums = [0,1,2]
// Output: 1

// Constraints:

// 1 <= nums.length <= 10^5
// 0 <= nums[i] < nums.length
// All the values of nums are unique.

// Approach #1 Brute Force [Time Limit Exceeded]
// The simplest method is to iterate over all the indices of the given numsnums array. For every index ii chosen, we find the element nums[i]nums[i] and increment the countcount for a new element added for the current index ii. Since nums[i]nums[i] has to act as the new index for finding the next element belonging to the set corresponding to the index ii, the new index is j=nums[i]j=nums[i].

// We continue this process of index updation and keep on incrementing the countcount for new elements added to the set corresponding to the index ii. Now, since all the elements in numsnums lie in the range (0,..., N-1)(0,...,N−1), the new indices generated will never lie outside the array size limits. But, we'll always reach a point where the current element becomes equal to the element nums[i]nums[i] with which we started the nestings in the first place. Thus, after this, the new indices generated will be just the repetitions of the previously generated ones, and thus would not lead to an increase in the size of the current set. Thus, this condition of the current number being equal to the starting number acts as the terminating condition for countcount incrementation for a particular index.

// We do the same process for every index chosen as the starting index. At the end, the maximum value of countcount obtained gives the size of the largest set.
// public class Solution {
//     public int arrayNesting(int[] nums) {
//         int res = 0;
//         for (int i = 0; i < nums.length; i++) {
//             int start = nums[i], count = 0;
//             do {
//                 start = nums[start];
//                 count++;
//             }
//             while (start != nums[i]);
//             res = Math.max(res, count);

//         }
//         return res;
//     }
// }

// Complexity Analysis

// Time complexity : O(n^2)O(n
// 2
//  ). In worst case, for example- [1,2,3,4,5,0], loop body will be executed n^2n
// 2
//   times.

// Space complexity : O(1). Constant space is used.

// Approach #2 Using Visited Array [Accepted]
// Algorithm

// In the last approach, we observed that in the worst case, all the elements of the numsnums array are added to the sets corresponding to all the starting indices. But, all these sets correspond to the same set of elements only, leading to redundant calculations.

// We consider a simple example and see how this problem can be resolved. From the figure below, we can see that the elements in the current nesting shown by arrows form a cycle. Thus, the same elements will be added to the current set irrespective of the first element chosen to be added to the set out of these marked elements.

// Thus, when we add an element nums[j]nums[j] to a set corresponding to any of the indices, we mark its position as visited in a visitedvisited array. This is done so that whenever this index is chosen as the starting index in the future, we do not go for redundant countcount calculations, since we've already considered the elements linked with this index, which will be added to a new(duplicate) set.

// By doing so, we ensure that the duplicate sets aren't considered again and again.

// Further, we can also observe that no two elements at indices ii and jj will lead to a jump to the same index kk, since it would require nums[i] = nums[j] = knums[i]=nums[j]=k, which isn't possible since all the elements are distinct. Also, because of the same reasoning, no element outside any cycle could lead to an element inside the cycle. Because of this, the use of visitedvisited array goes correctly.

// public class Solution {
//     public int arrayNesting(int[] nums) {
//         boolean[] visited = new boolean[nums.length];
//         int res = 0;
//         for (int i = 0; i < nums.length; i++) {
//             if (!visited[i]) {
//                 int start = nums[i], count = 0;
//                 do {
//                     start = nums[start];
//                     count++;
//                     visited[start] = true;
//                 }
//                 while (start != nums[i]);
//                 res = Math.max(res, count);
//             }
//         }
//         return res;
//     }
// }

// Complexity Analysis

// Time complexity : O(n). Every element of the numsnums array will be considered atmost once.

// Space complexity : O(n). visited array of size nn is used.

// Approach #3 Without Using Extra Space [Accepted]
// Algorithm

// In the last approach, the visitedvisited array is used just to keep a track of the elements of the array which have already been visited. Instead of making use of a separate array to keep track of the same, we can mark the visited elements in the original array numsnums itself. Since, the range of the elements can only be between 1 to 20,000, we can put a very large integer value \text{Integer.MAX_VALUE} at the position which has been visited. The rest process of traversals remains the same as in the last approach.

// public class Solution {
//     public int arrayNesting(int[] nums) {
//         int res = 0;
//         for (int i = 0; i < nums.length; i++) {
//             if (nums[i] != Integer.MAX_VALUE) {
//                 int start = nums[i], count = 0;
//                 while (nums[start] != Integer.MAX_VALUE) {
//                     int temp = start;
//                     start = nums[start];
//                     count++;
//                     nums[temp] = Integer.MAX_VALUE;
//                 }
//                 res = Math.max(res, count);
//             }
//         }
//         return res;
//     }
// }

// Complexity Analysis

// Time complexity : O(n)O(n). Every element of the numsnums array will be considered atmost once.

// Space complexity : O(1)O(1). Constant Space is used.

// Runtime: 12 ms, faster than 96.44% of C++ online submissions for Array Nesting.
// Memory Usage: 30 MB, less than 68.09% of C++ online submissions for Array Nesting.

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        // Using visisted array
        vector<bool> visited(nums.size(), false);
        auto result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                auto start = nums[i], count = 0;
                do
                {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                } while (start != nums[i]);
                result = std::max(result, count);
            }
        }
        return result;
    }
};

// Better solution
class bettersol
{
public:
    int n;
    vector<int> visit;
    int arrayNesting(vector<int> &nums)
    {
        int ans = 0;
        n = nums.size();
        visit = vector<int>(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (visit[i] == 0)
            {
                ans = max(ans, helper(nums, i));
            }
        }
        return ans;
    }
    int helper(vector<int> &nums, int i)
    {
        if (visit[i] == 1)
            return 0;
        visit[i] = 1;
        return 1 + helper(nums, nums[i]);
    }
};
