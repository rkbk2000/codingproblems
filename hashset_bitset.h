
// Runtime: 60 ms, faster than 99.52% of C++ online submissions for Design HashSet.
// Memory Usage: 43.5 MB, less than 51.12% of C++ online submissions for Design HashSet.
// Not any better than the vector<bool>
// https://leetcode.com/problems/design-hashset/submissions/

class MyHashSet
{
    bitset<1000001> hset;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        hset.set(key);
    }

    void remove(int key)
    {
        hset.set(key, false);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return hset.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */