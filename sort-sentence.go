// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

// A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
// Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

// Example 1:

// Input: s = "is2 sentence4 This1 a3"
// Output: "This is a sentence"
// Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
// Example 2:

// Input: s = "Myself2 Me1 I4 and3"
// Output: "Me Myself and I"
// Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.

// Constraints:

// 2 <= s.length <= 200
// s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
// The number of words in s is between 1 and 9.
// The words in s are separated by a single space.
// s contains no leading or trailing spaces.

// https: //leetcode.com/problems/sorting-the-sentence/

// Testcase:
// "is2 sentence4 This1 a3"
// "Myself2 Me1 I4 and3"
// "This1"

// Output:
// "This is a sentence"
// "Me Myself and I"
// "This"
// Runtime: 0 ms, faster than 100.00% of Go online submissions for Sorting the Sentence.
// Memory Usage: 2 MB, less than 96.85% of Go online submissions for Sorting the Sentence.

package main

import "strings"

func sortSentence(s string) string {
	tokens := strings.Fields(s)
	wc := len(tokens)
	words := make(map[int]string)
	for i := 0; i < wc; i++ {
		pos := tokens[i][len(tokens[i])-1] - '0'
		words[int(pos)] = tokens[i][:len(tokens[i])-1] + " "
	}

	ans := ""
	for i := 1; i <= wc; i++ {
		ans += words[i]
	}
	return ans[:len(ans)-1]
}
