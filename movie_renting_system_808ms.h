// Runtime: 808 ms, faster than 99.15% of C++ online submissions for Design Movie Rental System.
// Memory Usage: 296.9 MB, less than 87.42% of C++ online submissions for Design Movie Rental System.

//https : //leetcode.com/problems/design-movie-rental-system
class MovieRentingSystem
{
    typedef std::pair<int, int> pe;

    // avail - movie vs price,shop
    // rented - price vs shop, movie
    unordered_map<int, set<pe>> avail;

    map<int, set<pe>> rented;

    struct HashPair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    // prices- shop, movie  vs price
    unordered_map<pe, int, HashPair> prices;

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        // Create a pq of next available time vs weight,index
        for (auto &val : entries)
        {
            avail[val[1]].emplace(pe{val[2], val[0]});
            prices[pe{val[0], val[1]}] = val[2];
        }
    }

    vector<int> search(int movie)
    {
        vector<int> top5;
        auto cnt = 0;

        auto miter = avail.find(movie);
        if (miter != avail.end())
        {
            for (auto &it : miter->second)
            {
                top5.push_back(it.second);
                ++cnt;
                if (cnt == 5)
                    break;
            }
        }
        return top5;
    }

    void rent(int shop, int movie)
    {
        auto price = prices[pe{shop, movie}];
        // avail - movie vs price,shop
        // rented - price vs shop, movie
        avail[movie].erase(pe{price, shop});
        rented[price].emplace(pe{shop, movie});
    }

    void drop(int shop, int movie)
    {
        auto price = prices[pe{shop, movie}];
        // avail - movie vs price,shop
        // rented - price vs shop, movie
        rented[price].erase(pe{shop, movie});
        avail[movie].emplace(pe{price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> top5;
        auto cnt = 0;
        for (auto &it : rented)
        {
            for (auto &sm : it.second)
            {
                top5.push_back({sm.first, sm.second});
                ++cnt;
                if (cnt == 5)
                    break;
            }
            if (cnt == 5)
                break;
        }
        return top5;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */