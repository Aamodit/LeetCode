class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;
        
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        int m = meetings.size();
        int i = 0;
        
        while (i < m) {
            int currentTime = meetings[i][2];
            int j = i;
            
            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;
            
            while (j < m && meetings[j][2] == currentTime) {
                int x = meetings[j][0];
                int y = meetings[j][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                j++;
            }
            
            queue<int> q;
            for (int person : people) {
                if (knowsSecret[person]) {
                    q.push(person);
                }
            }
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : graph[curr]) {
                    if (!knowsSecret[neighbor]) {
                        knowsSecret[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            
            i = j;
        }
        
        vector<int> result;
        for (int person = 0; person < n; person++) {
            if (knowsSecret[person]) {
                result.push_back(person);
            }
        }
        
        return result;
    }
};
