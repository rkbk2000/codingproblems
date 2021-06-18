
// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

// Constraints:
// 0 <= key <= 10 pow6
// At most 104 calls will be made to add, remove, and contains.

// https://leetcode.com/problems/design-hashset/

// Runtime: 188 ms, faster than 18.73% of C++ online submissions for Design HashSet.
// Memory Usage: 39.5 MB, less than 96.02% of C++ online submissions for Design HashSet.

class MyHashSet
{
    vector<int> hset{};

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        if (!contains(key))
        {
            hset.push_back(key);
        }
    }

    void remove(int key)
    {
        auto iter = std::find(hset.begin(), hset.end(), key);
        if (iter != hset.end())
        {
            hset.erase(iter);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return (std::find(hset.begin(), hset.end(), key) != hset.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */