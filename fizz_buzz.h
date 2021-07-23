// Given an integer n, return a string array answer (1-indexed) where:

// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i if non of the above conditions are true.

// Example 1:

// Input: n = 3
// Output: ["1","2","Fizz"]
// Example 2:

// Input: n = 5
// Output: ["1","2","Fizz","4","Buzz"]
// Example 3:

// Input: n = 15
// Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

// Constraints:

// 1 <= n <= 10^4

// Testcase:
// 3
// 5
// 15
// 30

// Output:
// ["1","2","Fizz"]
// ["1","2","Fizz","4","Buzz"]
// ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
// ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz","16","17","Fizz","19","Buzz","Fizz","22","23","Fizz","Buzz","26","Fizz","28","29","FizzBuzz"]

// https://leetcode.com/problems/fizz-buzz/

// Runtime: 4 ms, faster than 78.38% of C++ online submissions for Fizz Buzz.
// Memory Usage: 7.2 MB, less than 87.00% of C++ online submissions for Fizz Buzz.
class SolutionNoMod
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans(n);
        array<string, 3> words = {"FizzBuzz", "Fizz", "Buzz"};

        // Divisible by 3 and 15
        for (auto i = 15; i <= n; i += 15)
        {
            ans[i - 1] = words[0];
        }

        // Divisible by 3
        for (auto i = 3; i <= n; i += 3)
        {
            if (ans[i - 1].empty())
                ans[i - 1] = words[1];
        }

        // Divisible by 5
        for (auto i = 5; i <= n; i += 5)
        {
            if (ans[i - 1].empty())
                ans[i - 1] = words[2];
        }

        for (auto i = 1; i <= n; i++)
        {
            if (ans[i - 1].empty())
                ans[i - 1] = std::to_string(i);
        }
        return ans;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fizz Buzz.
// Memory Usage: 7.3 MB, less than 87.00% of C++ online submissions for Fizz Buzz.
class Solution100
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans(n);
        for (auto i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
            {
                ans[i - 1] = "FizzBuzz";
            }
            else if (i % 3 == 0)
            {
                ans[i - 1] = "Fizz";
            }
            else if (i % 5 == 0)
            {
                ans[i - 1] = "Buzz";
            }
            else
            {
                ans[i - 1] = std::to_string(i);
            }
        }
        return ans;
    }
};