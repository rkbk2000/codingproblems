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

// Runtime: 4 ms, faster than 95.60% of Go online submissions for Fizz Buzz.
// Memory Usage: 3.5 MB, less than 63.00% of Go online submissions for Fizz Buzz.

func fizzBuzz(n int) []string {
	ans := make([]string, n)

	for i := 1; i <= n; i++ {
		switch {
		case i%15 == 0:
			ans[i-1] = "FizzBuzz"
		case i%3 == 0:
			ans[i-1] = "Fizz"
		case i%5 == 0:
			ans[i-1] = "Buzz"
		default:
			ans[i-1] = strconv.Itoa(i)
		}
	}
	return ans
}