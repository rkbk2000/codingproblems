// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10^-5 of the actual answer will be accepted.

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

// Constraints:

// -10^5 <= num <= 10^5
// There will be at least one element in the data structure before calling findMedian.
// At most 5 * 104 calls will be made to addNum and findMedian.

// Follow up:

// If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

// Testcase:
// ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
// [[],[1],[2],[],[3],[]]
// ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian", "addNum","addNum", "findMedian", "addNum", "findMedian"]
// [[],[1],[],[2],[],[3],[],[4],[5],[],[6],[]]
// ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian", "addNum","addNum", "findMedian", "addNum", "findMedian"]
// [[],[1],[],[1],[],[1],[],[1],[1],[],[1],[]]
// ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian", "addNum","addNum", "findMedian", "addNum", "findMedian"]
// [[],[9],[],[8],[],[7],[],[6],[5],[],[4],[]]

// Output:
// [null,null,null,1.50000,null,2.00000]
// [null,null,1.00000,null,1.50000,null,2.00000,null,null,3.00000,null,3.50000]
// [null,null,1.00000,null,1.00000,null,1.00000,null,null,1.00000,null,1.00000]
// [null,null,9.00000,null,8.50000,null,8.00000,null,null,7.00000,null,6.50000]

// Runtime: 344 ms, 6.37%
// Memory Usage: 46.8 MB, 55.13%

// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder
{
    std::vector<int> nums;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        auto pos = std::upper_bound(nums.begin(), nums.end(), num);
        nums.insert(pos, num);
    }

    double findMedian()
    {
        int mid = nums.size() / 2;
        if (nums.size() % 2)
        {
            // Odd size, return middle element
            return nums[mid];
        }
        return (nums[mid] + nums[mid - 1]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Resizing a vector is costly. Check the 2 q solution:
// https://leetcode.com/problems/find-median-from-data-stream/discuss/74184/Share-my-soultion-c%2B%2B-148ms