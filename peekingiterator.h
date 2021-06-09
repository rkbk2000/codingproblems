/*
 * https://leetcode.com/problems/peeking-iterator/submissions/
 * https://github.com/google/guava/blob/703ef758b8621cfbab16814f01ddcc5324bdea33/guava-gwt/src-super/com/google/common/collect/super/com/google/common/collect/Iterators.java#L1125
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator
{
    bool peaked;
    int top;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        peaked = false;
        top = 0;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        if (!peaked)
        {
            top = Iterator::next();
            peaked = true;
        }
        return top;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        if (peaked)
        {
            peaked = false;
            return top;
        }
        return Iterator::next();
    }

    bool hasNext() const
    {
        return peaked || Iterator::hasNext();
    }
};