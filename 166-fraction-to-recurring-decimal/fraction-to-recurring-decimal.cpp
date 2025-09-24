class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Convert to long long to avoid overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);
        
        // Integer part
        result += to_string(num / den);
        long long remainder = num % den;
        if (remainder == 0) return result;
        
        result += ".";
        
        // Map remainder to position in result string
        unordered_map<long long, int> remainderPos;
        
        while (remainder != 0) {
            if (remainderPos.count(remainder)) {
                result.insert(remainderPos[remainder], "(");
                result += ")";
                break;
            }
            
            remainderPos[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};
