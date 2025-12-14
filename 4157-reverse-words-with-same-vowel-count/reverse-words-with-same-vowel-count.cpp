class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(), count_vowels = 0, i = 0;
        string vowels = "aeiou";

        while(i < n) {
            if(s[i] == ' ')
                break;

            if(vowels.find(s[i]) != string::npos)
                ++count_vowels;

            i += 1;
        }

        i += 1;
        int l = i, count = 0;

        while(i < n) {
            if(s[i] == ' ') {
                if(count == count_vowels)
                    reverse(begin(s) + l, begin(s) + i);

                count = 0, l = i + 1;
            }

            if(vowels.find(s[i]) != string::npos)
                ++count;
            
            i += 1;
        }

        if(count == count_vowels)
            reverse(begin(s) + l, begin(s) + i);

        return s;
    }
};