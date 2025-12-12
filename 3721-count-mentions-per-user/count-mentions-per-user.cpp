class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // Sort by timestamp, OFFLINE before MESSAGE if same timestamp
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta != tb) return ta < tb;
            return a[0] == "OFFLINE" && b[0] == "MESSAGE";
        });

        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineUntil(numberOfUsers, 0);

        for (auto& e : events) {
            int time = stoi(e[1]);

            if (e[0] == "OFFLINE") {
                int id = stoi(e[2]);
                offlineUntil[id] = time + 60;
            } else { // MESSAGE
                string s = e[2];

                if (s == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        mentions[i]++;
                }
                else if (s == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (time >= offlineUntil[i])
                            mentions[i]++;
                    }
                }
                else {
                    // id<number> tokens
                    stringstream ss(s);
                    string tok;
                    while (ss >> tok) {
                        int id = stoi(tok.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }
        return mentions;
    }
};
