// https://leetcode.com/problems/design-hashset
// Consumes more memory but efficient in general
// Runtime: 56 ms, faster than 99.78% of C++ online submissions for Design HashSet.
// Memory Usage: 43.5 MB, less than 51.12% of C++ online submissions for Design HashSet.
class MyHashSet
{
    vector<bool> hset;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        // Avoid 0 index
        hset = vector<bool>(1000001, false);
    }

    void add(int key)
    {
        hset[key] = true;
    }

    void remove(int key)
    {
        hset[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return hset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */