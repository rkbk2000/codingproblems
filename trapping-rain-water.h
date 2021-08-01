// https://leetcode.com/problems/trapping-rain-water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:

// n == height.length
// 0 <= n <= 3 * 10^4
// 0 <= height[i] <= 10^5

// Solution:
// Approach 1: Brute force
// Intuition

// Do as directed in question. For each element in the array, we find the maximum level of water it can trap after the rain, which is equal to the minimum of maximum height of bars on both the sides minus its own height.

// Algorithm

// Initialize ans=0ans=0
// Iterate the array from left to right:
// Initialize \text{left\_max}=0left_max=0 and \text{right\_max}=0right_max=0
// Iterate from the current element to the beginning of array updating:
// \text{left\_max}=\max(\text{left\_max},\text{height}[j])left_max=max(left_max,height[j])
// Iterate from the current element to the end of array updating:
// \text{right\_max}=\max(\text{right\_max},\text{height}[j])right_max=max(right_max,height[j])
// Add \min(\text{left\_max},\text{right\_max}) - \text{height}[i]min(left_max,right_max)−height[i] to \text{ans}ans

// Complexity Analysis

// Time complexity: O(n^2)O(n
// 2
//  ). For each element of array, we iterate the left and right parts.

// Space complexity: O(1)O(1) extra space.

// Approach 2: Dynamic Programming
// Intuition

// In brute force, we iterate over the left and right parts again and again just to find the highest bar size upto that index. But, this could be stored. Voila, dynamic programming.

// The concept is illustrated as shown:

// Dynamic programming

// Algorithm

// Find maximum height of bar from the left end upto an index i in the array \text{left\_max}left_max.
// Find maximum height of bar from the right end upto an index i in the array \text{right\_max}right_max.
// Iterate over the \text{height}height array and update ans:
// Add \min(\text{left\_max}[i],\text{right\_max}[i]) - \text{height}[i]min(left_max[i],right_max[i])−height[i] to \text{ans}ans

// Complexity analysis

// Time complexity: O(n)O(n).

// We store the maximum heights upto a point using 2 iterations of O(n)O(n) each.
// We finally update \text{ans}ans using the stored values in O(n)O(n).
// Space complexity: O(n)O(n) extra space.

// Additional O(n)O(n) space for \text{left\_max}left_max and \text{right\_max}right_max arrays than in Approach 1.

// Approach 3: Using stacks
// Intuition

// Instead of storing the largest bar upto an index as in Approach 2, we can use stack to keep track of the bars that are bounded by longer bars and hence, may store water. Using the stack, we can do the calculations in only one iteration.

// We keep a stack and iterate over the array. We add the index of the bar to the stack if bar is smaller than or equal to the bar at top of stack, which means that the current bar is bounded by the previous bar in the stack. If we found a bar longer than that at the top, we are sure that the bar at the top of the stack is bounded by the current bar and a previous bar in the stack, hence, we can pop it and add resulting trapped water to \text{ans}ans.

// Algorithm

// Use stack to store the indices of the bars.
// Iterate the array:
// While stack is not empty and \text{height[current]}>\text{height[st.top()]}height[current]>height[st.top()]
// It means that the stack element can be popped. Pop the top element as \text{top}top.
// Find the distance between the current element and the element at top of stack, which is to be filled. \text{distance} = \text{current} - \text{st.top}() - 1distance=current−st.top()−1
// Find the bounded height \text{bounded\_height} = \min(\text{height[current]}, \text{height[st.top()]}) - \text{height[top]}bounded_height=min(height[current],height[st.top()])−height[top]
// Add resulting trapped water to answer \text
// {
//     ans
// }
// \mathrel{+} = \text { distance }
// \times \text{bounded\_height} ans += distance×bounded_height
//                                              Push current index to top of the stack
//                                                  Move \text{current} current to the next position

//                                                      Complexity analysis

//                                                          Time complexity : O(n) O(n)
//                                                                                .Single iteration of O(n) O(n) in which each bar can be touched at most
//                                                                                twice(due to insertion and deletion from stack) and
//                                          insertion and deletion from stack takes O(1) O(1) time.Space complexity : O(n) O(n).Stack can take upto O(n) O(n) space in case of stairs - like or
//                                      flat structure.

//                                      Approach 4 : Using 2 pointers
//                                                       Intuition

//                                                           As in Approach 2,
//     instead of computing the left and right parts seperately, we may think of some way to do it in one iteration.From the figure in dynamic programming approach, notice that as long as \text{right\_max}[i] >\text{left\_max}[i] right_max[i] > left_max[i](from element 0 to 6), the water trapped depends upon the left_max, and similar is the case when \text{left\_max}[i] >\text{right\_max}[i] left_max[i] > right_max[i](from element 8 to 11).So, we can say that if there is a larger bar at one end(say right), we are assured that the water trapped would be dependant on height of bar in current direction(from left to right).As soon as we find the bar at other end(right) is smaller, we start iterating in opposite direction(from right to left).We must maintain \text{left\_max} left_max and \text{right\_max} right_max during the iteration, but now we can do it in one iteration using 2 pointers, switching between the two.

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      Algorithm

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      Initialize \text{left} left pointer to 0 and \text{right} right pointer to size - 1 While \text{left} < \text{right} left < right,
//     do : If \text{height[left]} height[left] is smaller than \text{height[right]} height[right] If \text
// {
//     height[left]
// }
// \geq \text{left\_max} height[left]≥left_max, update \text{left\_max} left_max
//                                                      Else add \text{left\_max} -\text{height[left]} left_max−height[left] to \text{ans} ans
//                                                                                     Add 1 to \text{left} left.Else
//                                                                                         If \text { height[right] } \geq \text{right\_max}height[right]≥right_max, update \text{right\_max}right_max
// Else add \text{right\_max}-\text{height[right]}right_max−height[right] to \text{ans}ans
// Subtract 1 from \text{right}right.
// Current
// 1 / 11

// Complexity analysis

// Time complexity: O(n)O(n). Single iteration of O(n)O(n).
// Space complexity: O(1)O(1) extra space. Only constant space required for \text{left}left, \text{right}right, \text{left\_max}left_max and \text{right\_max}right_max.

// Using a stack
class SolutionStack
{
public:
    int trap(vector<int> &height)
    {

        int sz = height.size();
        stack<int> hst;
        int sum = 0, cur = 0;

        while (cur < sz)
        {

            while (!hst.empty() && height[cur] > height[hst.top()])
            {
                auto top = hst.top();
                hst.pop();
                if (hst.empty())
                {
                    // We have reached the end
                    break;
                }

                auto dist = cur - hst.top() - 1;
                auto bh = std::min(height[cur], height[hst.top()]) - height[top];
                sum += dist * bh;
            }
            // Push an element as long as its height is less than current top element
            hst.push(cur++);
        }
        return sum;
    }
};

// Using two pointers
int trap(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right)
    {
        if (height[left] < height[right])
        {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else
        {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

// Using DP
int trapDP(vector<int> &height)
{
    if (height.empty())
        return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++)
    {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++)
    {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}