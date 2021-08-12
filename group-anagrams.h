// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lower-case English letters.

// https://leetcode.com/problems/group-anagrams/
// Runtime: 28 ms, faster than 89.97% of C++ online submissions for Group Anagrams.
// Memory Usage: 18.8 MB, less than 89.59% of C++ online submissions for Group Anagrams.
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagrams;

        // Sort each string and use it as the key for hashmap
        for (auto s : strs)
        {
            auto key = s;
            std::sort(key.begin(), key.end());
            anagrams[key].push_back(s);
        }

        // Convert  hashmap into result vector
        int i = 0;
        vector<vector<string>> result(anagrams.size());
        for (auto &kv : anagrams)
        {
            result[i++] = vector<string>(kv.second.begin(), kv.second.end());
        }
        return result;
    }
};

// Another method is to use frequency strings as the key. For e.g. aba = a2b1, tab =a1b1t1 etc.