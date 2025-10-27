class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        
        // Count devices in each non-empty row
        for (auto& row : bank) {
            int count = 0;
            for (char c : row)
                if (c == '1') count++;
            if (count > 0)
                devices.push_back(count);
        }
        
        // Calculate total beams between consecutive non-empty rows
        int totalBeams = 0;
        for (int i = 0; i + 1 < devices.size(); i++)
            totalBeams += devices[i] * devices[i + 1];
        
        return totalBeams;
    }
};
