// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

// Constraints:

// 1 <= beginWord.length <= 5
// endWord.length == beginWord.length
// 1 <= wordList.length <= 1000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.

// https://leetcode.com/problems/word-ladder-ii/

// Testcase:
// "hit"
// "cog"
// ["hot","dot","dog","lot","log","cog"]
// "hit"
// "cog"
// ["hot","dot","dog","lot","log"]

// Output:
// [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// []

// Runtime: 12 ms, faster than 79.39% of C++ online submissions for Word Ladder II.
// Memory Usage: 9.8 MB, less than 60.18% of C++ online submissions for Word Ladder II.

class Solution
{
    unordered_map<string, vector<string>> adjWords;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;

public:
    // Find the neighbours of current word. All words that differ by one character are the neighbours of current word.
    // We find it by replacing each character of the current word with 'a' to 'z' and checking if it is present in the input set
    vector<string> getNeighbours(string &word, const unordered_set<string> &wordSet)
    {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++)
        {
            char orgChar = word[i];

            // Replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;

                // Skip if the character is same as original or if the word is not present in the wordSet
                if (c == orgChar || !wordSet.count(word))
                {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = orgChar;
        }
        return neighbors;
    }

    // Backtracking to find all shortest paths in the DAG created using BFS
    void backtrack(const string &source, const string &destination)
    {
        // Store the path as we have reached the endWord
        if (source == destination)
        {
            shortestPaths.push_back(currPath);
        }
        for (auto &word : adjWords[source])
        {
            currPath.push_back(word);
            backtrack(word, destination);
            currPath.pop_back();
        }
    }

    void breadth_first_search(const string &beginWord, const string &endWord, unordered_set<string> &wordSet)
    {
        // Queue for the BFS
        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);

        // Set to track queued words
        unordered_set<string> ennqueued;

        while (!q.empty())
        {
            // Visited will store the words of current layer
            vector<string> visited;

            for (int i = q.size() - 1; i >= 0; i--)
            {
                string currWord = q.front();
                q.pop();

                // getNeighbours will have the adjacent words of the currWord
                vector<string> neighbors = getNeighbours(currWord, wordSet);
                for (auto &word : neighbors)
                {
                    visited.push_back(word);
                    // add the edge from currWord to word in the list
                    adjWords[currWord].push_back(word);
                    auto it = ennqueued.emplace(word);
                    if (it.second)
                    {
                        q.push(word);
                    }
                }
            }
            // Remove the words of the previous layer
            for (auto &word : visited)
            {
                wordSet.erase(word);
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // Create a set for the entries present in wordList so that we could use it in the BFS
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // Build the DAG using BFS
        breadth_first_search(beginWord, endWord, wordSet);

        // Shirtest path always starts from beginWord
        currPath = {beginWord};
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);

        return shortestPaths;
    }
};