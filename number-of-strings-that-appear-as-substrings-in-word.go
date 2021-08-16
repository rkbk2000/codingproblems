// Runtime: 0 ms, faster than 100.00% of Go online submissions for Number of Strings That Appear as Substrings in Word.
// Memory Usage: 2.7 MB, less than 100.00% of Go online submissions for Number of Strings That Appear as Substrings in Word.
func numOfStrings(patterns []string, word string) int {
	result := 0
	for _, pattern := range patterns {
		if strings.Contains(word, pattern) {
			result++
		}
	}
	return result
}
