// https://leetcode.com/problems/map-sum-pairs/

// Implement the MapSum class:

// MapSum() Initializes the MapSum object.
// void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
// int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

// Example 1:

// Input
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
// Output
// [null, null, 3, null, 5]

// Explanation
// MapSum mapSum = new MapSum();
// mapSum.insert("apple", 3);
// mapSum.sum("ap");           // return 3 (apple = 3)
// mapSum.insert("app", 2);
// mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

// Constraints:

// 1 <= key.length, prefix.length <= 50
// key and prefix consist of only lowercase English letters.
// 1 <= val <= 1000
// At most 50 calls will be made to insert and sum.

// Testcase:
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple",3], ["ap"], ["app",2], ["ap"]]
// ["MapSum", "insert", "sum", "insert", "insert", "sum"]
// [[], ["apple",3], ["ap"], ["app",2], ["apple", 2], ["ap"]]

// output:
// [null,null,3,null,5]
// [null,null,3,null,null,4]

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Map Sum Pairs.
// Memory Usage: 7.8 MB, less than 87.17% of C++ online submissions for Map Sum Pairs.

class MapSum
{
    map<string, int> sum_map;

public:
    /** Initialize your data structure here. */
    MapSum()
    {
    }

    void insert(string key, int val)
    {
        auto it = sum_map.emplace(key, val);
        if (!it.second)
        {
            it.first->second = val;
        }
    }

    int sum(string prefix)
    {
        auto lb = sum_map.lower_bound(prefix);

        auto ps = prefix.size();
        auto sum = 0;
        if (lb != sum_map.end())
        {
            for (auto it = lb; it != sum_map.end(); ++it)
            {
                // Check if there is a prefix match
                auto &key = it->first;
                if (key.compare(0, ps, prefix) == 0)
                {
                    sum += it->second;
                }
                else
                {
                    break;
                }
            }
        }

        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */