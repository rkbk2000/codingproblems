

// https://leetcode.com/problems/design-hashset
// Result : time limit exceeded
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
            std::sort(hset.begin(), hset.end());
        }
    }

    void remove(int key)
    {
        if (contains(key))
        {
            auto iter = std::find(hset.begin(), hset.end(), key);
            hset.erase(iter);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return std::binary_search(hset.begin(), hset.end(), key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */