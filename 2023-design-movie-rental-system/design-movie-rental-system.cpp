
class MovieRentingSystem {
    // (shop, movie) -> price
    map<pair<int,int>, int> priceMap;

    // movie -> set of (price, shop)
    unordered_map<int, set<pair<int,int>>> available;

    // set of (price, shop, movie)
    set<tuple<int,int,int>> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[{shop, movie}] = price;
            available[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            auto &s = available[movie];
            int cnt = 0;
            for (auto &p : s) {
                res.push_back(p.second);
                if (++cnt == 5) break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &t : rented) {
            auto [price, shop, movie] = t;
            res.push_back({shop, movie});
            if (++cnt == 5) break;
        }
        return res;
    }
};
