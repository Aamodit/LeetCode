class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequencies
        for (int n : nums) {
            freq[n]++;
        }
        
        // Step 2: Find maximum frequency
        int maxFreq = 0;
        for (auto& [num, count] : freq) {
            maxFreq = max(maxFreq, count);
        }
        
        // Step 3: Count total elements that appear with max frequency
        int result = 0;
        for (auto& [num, count] : freq) {
            if (count == maxFreq) {
                result += count;
            }
        }
        
        return result;
    }
};
