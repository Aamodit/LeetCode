
struct Packet {
    int source, dest, time;
};

struct TupleHash {
    size_t operator()(const tuple<int, int, int>& t) const {
        auto [a, b, c] = t;
        return ((size_t)a * 1315423911u) ^ ((size_t)b * 2654435761u) ^
               ((size_t)c * 97531u);
    }
};

class Router {
    int limit;
    deque<Packet> q;
    unordered_set<tuple<int, int, int>, TupleHash> seen;
    unordered_map<int, vector<int>> destMap;

public:
    Router(int memoryLimit) { limit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> key = {source, destination, timestamp};
        if (seen.count(key))
            return false; // duplicate

        // Evict if at capacity
        if ((int)q.size() == limit) {
            Packet old = q.front();
            q.pop_front();
            seen.erase({old.source, old.dest, old.time});
            auto& vec = destMap[old.dest];
            // remove old.time from vector (timestamps increasing → oldest is
            // front)
            if (!vec.empty() && vec.front() == old.time) {
                vec.erase(vec.begin()); // O(1) amortized since always front
            } else {
                // fallback: binary search (should rarely happen)
                auto it = lower_bound(vec.begin(), vec.end(), old.time);
                if (it != vec.end() && *it == old.time)
                    vec.erase(it);
            }
        }

        // Insert new packet
        q.push_back({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty())
            return {};
        Packet p = q.front();
        q.pop_front();
        seen.erase({p.source, p.dest, p.time});
        auto& vec = destMap[p.dest];
        if (!vec.empty() && vec.front() == p.time) {
            vec.erase(vec.begin());
        } else {
            auto it = lower_bound(vec.begin(), vec.end(), p.time);
            if (it != vec.end() && *it == p.time)
                vec.erase(it);
        }
        return {p.source, p.dest, p.time};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destMap.find(destination);
        if (it == destMap.end())
            return 0;
        auto& vec = it->second;
        auto lo = lower_bound(vec.begin(), vec.end(), startTime);
        auto hi = upper_bound(vec.begin(), vec.end(), endTime);
        return (int)(hi - lo);
    }
};
