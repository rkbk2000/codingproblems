
// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.

// // Testcase:
// ["i", "love", "leetcode", "i", "love", "coding"]
// 2
// ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"]
// 4
// // Output:
// ["i","love"]
// ["the","is","sunny","day"]

// https://leetcode.com/problems/top-k-frequent-words/submissions/

// Runtime: 20 ms, faster than 16.39% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 12.8 MB, less than 13.69% of C++ online submissions for Top K Frequent Words.

class Solution
{
    struct freqstr
    {
        int count;
        string word;

        bool operator()(const freqstr &lhs, const freqstr &rhs) const
        {
            // If both are same return lexicographically smaller
            if (lhs.count == rhs.count)
            {
                return lhs.word > rhs.word;
            }

            //Return the one with larger count
            return lhs.count < rhs.count;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        std::map<string, int> wordcount;

        for (auto &word : words)
        {
            auto it = wordcount.find(word);
            if (it != wordcount.end())
            {
                it->second++;
            }
            else
            {
                wordcount[word] = 1;
            }
        }

        // typedef pair <int, string> freqstr;
        std::priority_queue<freqstr, vector<freqstr>, freqstr> freq;

        for (auto &it : wordcount)
        {
            freq.emplace(freqstr{it.second, it.first});
        }

        vector<string> ans;
        for (auto i = 0; i < k; i++)
        {
            ans.push_back(freq.top().word);
            freq.pop();
        }
        return ans;
    }
};

// Unonrdered map with direc count increment
// Runtime: 4 ms, faster than 99.68% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 12.9 MB, less than 13.69% of C++ online submissions for Top K Frequent Words.

class Solution
{
    struct freqstr
    {
        int count;
        string word;

        bool operator()(const freqstr &lhs, const freqstr &rhs) const
        {
            // If both are same return lexicographically smaller
            if (lhs.count == rhs.count)
            {
                return lhs.word > rhs.word;
            }

            //Return the one with larger count
            return lhs.count < rhs.count;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        std::unordered_map<string, int> wordcount;

        for (auto &word : words)
        {
            wordcount[word]++;
        }

        // typedef pair <int, string> freqstr;
        std::priority_queue<freqstr, vector<freqstr>, freqstr> freq;

        for (auto &it : wordcount)
        {
            freq.emplace(freqstr{it.second, it.first});
        }

        vector<string> ans;
        for (auto i = 0; i < k; i++)
        {
            ans.push_back(freq.top().word);
            freq.pop();
        }
        return ans;
    }
};