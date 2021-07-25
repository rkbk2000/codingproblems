// There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

// The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).

// Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

// For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.
// You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

// Given students and mentors, return the maximum compatibility score sum that can be achieved.

// Example 1:

// Input: students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
// Output: 8
// Explanation: We assign students to mentors in the following way:
// - student 0 to mentor 2 with a compatibility score of 3.
// - student 1 to mentor 0 with a compatibility score of 2.
// - student 2 to mentor 1 with a compatibility score of 3.
// The compatibility score sum is 3 + 2 + 3 = 8.
// Example 2:

// Input: students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]
// Output: 0
// Explanation: The compatibility score of any student-mentor pair is 0.

// Constraints:

// m == students.length == mentors.length
// n == students[i].length == mentors[j].length
// 1 <= m, n <= 8
// students[i][k] is either 0 or 1.
// mentors[j][k] is either 0 or 1.

// Calculate the compatibility score for each student-mentor pair.
// Try every permutation of students with the original mentors array.

// Testcase:
// [[1,1,0],[1,0,1],[0,0,1]]
// [[1,0,0],[0,0,1],[1,1,0]]
// [[0,1,0,1,1,1],[1,0,0,1,0,1],[1,0,1,1,0,0]]
// [[1,0,0,0,0,1],[0,1,0,0,1,1],[0,1,0,0,1,1]]

// Output:
// 8
// 10

// https://leetcode.com/problems/maximum-compatibility-score-sum/

// Runtime: 228 ms, faster than 100.00% of C++ online submissions for Maximum Compatibility Score Sum.
// Memory Usage: 9.9 MB, less than 100.00% of C++ online submissions for Maximum Compatibility Score Sum.

// As the permutations are very small, it is ok to try and get the result for all permutations
class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int maxscore = 0, rowsize = students.size(), colsize = students[0].size();

        // Temporary vector to create possible permutations
        vector<int> indexes(rowsize);
        for (auto i = 0; i < rowsize; i++)
        {
            indexes[i] = i;
        }

        do
        {
            int curmax = 0;
            for (auto i = 0; i < rowsize; i++)
            {
                // Assign ith student to ith mentor
                auto &student = students[indexes[i]];
                auto &mentor = mentors[i];
                for (auto j = 0; j < colsize; j++)
                {
                    if (student[j] == mentor[j])
                    {
                        ++curmax;
                    }
                }
            }
            maxscore = std::max(maxscore, curmax);
        } while (std::next_permutation(indexes.begin(), indexes.end()));
        return maxscore;
    }
};