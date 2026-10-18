class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res = "";
        
        // Determine the sign
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }
        
        // Convert to long long to prevent overflow
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        // Integral part
        res += to_string(num / den);
        
        long long rem = num % den;
        if (rem == 0) return res;
        
        res += ".";
        
        // Fractional part
        unordered_map<long long, int> m;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                res.insert(m[rem], "(");
                res += ")";
                break;
            }
            
            m[rem] = res.length();
            rem *= 10;
            res += to_string(rem / den);
            rem %= den;
        }
        
        return res;
    }
};