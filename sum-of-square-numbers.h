// 633. Sum of Square Numbers
// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:

// Input: c = 3
// Output: false
// Example 3:

// Input: c = 4
// Output: true
// Example 4:

// Input: c = 2
// Output: true
// Example 5:

// Input: c = 1
// Output: true

// Constraints:

// 0 <= c <= 2^31 - 1

// Runtime: 204 ms, faster than 8.35% of C++ online submissions for Sum of Square Numbers.
// Memory Usage: 62.3 MB, less than 7.58% of C++ online submissions for Sum of Square Numbers.

// Using hashset
class Solution
{
public:
    bool judgeSquareSum(int c)
    {

        unordered_set<int> squares;
        int sc = sqrt(c);

        for (int i = 0; i <= sc; i++)
        {
            int sq = i * i;
            squares.emplace(sq);
            if (squares.count(c - sq))
            {
                return true;
            }
        }
        return false;
    }
};

// Better approach
class SolutionSq
{
public:
    bool judgeSquareSum(int c)
    {
        int sc = sqrt(c);

        for (int i = 0; i <= sc; i++)
        {
            int sq = i * i;
            int ot = sqrt(c - sq);
            if (c - sq == ot * ot)
                return true;
        }
        return false;
    }
};

// Approach 1: Brute Force
// The simplest solution would be to consider every possible combination of integers aa and bb and check if the sum of their squares equals cc. Now, both aa and bb can lie within the range (0,\sqrt{c})(0,
// c
// ​
//  ). Thus, we need to check for the values of aa and bb in this range only.

// Complexity Analysis

// Time complexity : O(c)O(c). Two loops upto \sqrt{c}
// c
// ​
//  . Here, cc refers to the given integer(sum of squares).

// Space complexity : O(1)O(1). Constant extra space is used.

// Approach 2: Better Brute Force
// We can improve the last solution, if we make the following observation. For any particular aa chosen, the value of bb required to satisfy the equation a^2 + b^2 = ca
// 2
//  +b
// 2
//  =c will be such that b^2 = c - a^2b
// 2
//  =c−a
// 2
//  . Thus, we need to traverse over the range (0, \sqrt{c})(0,
// c
// ​
//  ) only for considering the various values of aa. For every current value of aa chosen, we can determine the corresponding b^2b
// 2
//   value and check if it is a perfect square or not. If it happens to be a perfect square, cc is a sum of squares of two integers, otherwise not.

// Now, to determine, if the number c - a^2c−a
// 2
//   is a perfect square or not, we can make use of the following theorem:

// The square of n^{th}n
// th
//   positive integer can be represented as a sum of first nn odd positive integers.

// Or in mathematical terms:

// n^2 = 1 + 3 + 5 + ... + (2 \cdot n-1) = \sum_{i=1}^{n} (2 \cdot i - 1)n
// 2
//  =1+3+5+...+(2⋅n−1)=∑
// i=1
// n
// ​
//  (2⋅i−1)

// To look at the proof of this statement, look at the L.H.S. of the above statement.

// \begin{aligned} &1 + 3 + 5 + \ldots + (2 \cdot n-1) \\ = \; &(2 \cdot 1-1) + (2 \cdot 2-1) + (2 \cdot 3-1) + \ldots + (2 \cdot n-1) \\ = \; &2 \cdot (1+2+3+....+n) - (\underbrace{1+1+ \ldots +1}_{n\text{ times}}) \\ = \; &2 \cdot \frac{n\;(n+1)}{2} - n \\ = \; &n\;(n+1) - n \\ = \; &n^2 + n - n \\ = \; &n^2 \end{aligned}
// =
// =
// =
// =
// =
// =
// ​

// 1+3+5+…+(2⋅n−1)
// (2⋅1−1)+(2⋅2−1)+(2⋅3−1)+…+(2⋅n−1)
// 2⋅(1+2+3+....+n)−(
// n times
// 1+1+…+1
// ​

// ​
//  )
// 2⋅
// 2
// n(n+1)
// ​
//  −n
// n(n+1)−n
// n
// 2
//  +n−n
// n
// 2

// ​

// This completes the proof of the above statement.

// Complexity Analysis

// Time complexity : O(c)O(c). The total number of times the sumsum is updated is: 1 + 2 + 3 + \ldots + \sqrt{c} = \frac{\sqrt{c}\;(\sqrt{c}+1)}{2} = O(c)1+2+3+…+
// c
// ​
//  =
// 2
// c
// ​
//  (
// c
// ​
//  +1)
// ​
//  =O(c).

// Space complexity : O(1)O(1). Constant extra space is used.

// Approach 3: Using Sqrt Function
// Algorithm

// Instead of finding if c - a^2c−a
// 2
//   is a perfect square using sum of odd numbers, as done in the last approach, we can make use of the inbuilt sqrtsqrt function and check if \sqrt{c - a^2}
// c−a
// 2

// ​
//   turns out to be an integer. If it happens for any value of aa in the range [0, \sqrt{c}][0,
// c
// ​
//  ], we can return a True value immediately.

// Complexity Analysis

// Time complexity : O\big(\sqrt{c}\log c\big)O(
// c
// ​
//  logc). We iterate over \sqrt{c}
// c
// ​
//   values for choosing aa. For every aa chosen, finding square root of c - a^2c−a
// 2
//   takes O\big(\log c\big)O(logc) time in the worst case.

// Space complexity : O(1)O(1). Constant extra space is used.

// Approach 4: Binary Search
// Algorithm

// Another method to check if c - a^2c−a
// 2
//   is a perfect square, is by making use of Binary Search. The method remains same as that of a typical Binary Search to find a number. The only difference lies in that we need to find an integer, midmid in the range [0, c - a^2][0,c−a
// 2
//  ], such that this number is the square root of c - a^2c−a
// 2
//  . Or in other words, we need to find an integer, midmid, in the range [0, c - a^2][0,c−a
// 2
//  ], such that mid \times mid = c - a^2mid×mid=c−a
// 2
//  .

// The following animation illustrates the search process for a particular value of c - a^2 = 36c−a
// 2
//  =36.

// Current
// 1 / 6

// Complexity Analysis

// Time complexity : O\big(\sqrt{c}\log c\big)O(
// c
// ​
//  logc). Binary search taking O\big(\log c\big)O(logc) in the worst case is done for \sqrt{c}
// c
// ​
//   values of aa.

// Space complexity : O(\log c)O(logc). Binary Search will take O(\log c)O(logc) space.

// Approach 5: Fermat Theorem
// Algorithm

// This approach is based on the following statement, which is based on Fermat's Theorem:

// Any positive number nn is expressible as a sum of two squares if and only if the prime factorization of nn, every prime of the form (4k+3)(4k+3) occurs an even number of times.

// By making use of the above theorem, we can directly find out if the given number cc can be expressed as a sum of two squares.

// To do so we simply find all the prime factors of the given number cc, which could range from [2,\sqrt{c}][2,
// c
// ​
//  ] along with the count of those factors, by repeated division. If at any step, we find out that the number of occurences of any prime factor of the form (4k+3)(4k+3) occurs an odd number of times, we can return a False value.

// In case, cc itself is a prime number, it won't be divisible by any of the primes in the [2,\sqrt{c}][2,
// c
// ​
//  ]. Thus, we need to check if cc can be expressed in the form of 4k+34k+3. If so, we need to return a False value, indicating that this prime occurs an odd number(1) of times.

// Otherwise, we can return a True value.

// The proof of this theorem includes the knowledge of advanced mathematics and is beyond the scope of this article. However, interested reader can refer to this documentation.

// Complexity Analysis

// Time complexity : O\big(\sqrt{c}\log c\big)O(
// c
// ​
//  logc). We find the factors of cc and their count using repeated division. We check for the factors in the range [0, \sqrt{c}][0,
// c
// ​
//  ]. The maximum number of times a factor can occur(repeated division can be done) is \log nlogn(considering 2 as the only factor, c=2^xc=2
// x
//  . Thus, x=\log cx=logc).

// Space complexity : O(1)O(1). Constant space is used.
