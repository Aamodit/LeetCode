class Solution {
public:
    // Compute gain of adding one student
    double gain(int p, int t) {
        return (double)(p + 1) / (t + 1) - (double)p / t;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap by gain
        priority_queue<pair<double, pair<int,int>>> pq;
        
        for (auto &c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), {p, t}});
        }

        // Assign extra students
        while (extraStudents--) {
            auto [g, pt] = pq.top(); pq.pop();
            int p = pt.first, t = pt.second;
            p++; t++;
            pq.push({gain(p, t), {p, t}});
        }

        // Compute final average
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, pt] = pq.top(); pq.pop();
            int p = pt.first, t = pt.second;
            sum += (double)p / t;
        }
        return sum / classes.size();
    }
};