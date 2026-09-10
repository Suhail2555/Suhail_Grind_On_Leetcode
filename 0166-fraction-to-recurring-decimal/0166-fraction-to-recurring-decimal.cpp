class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0)
            return "0";

        string ans = "";

        // Check negative
        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";

        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        // Integer part
        ans += to_string(num / den);

        // Remainder
        long long rem = num % den;

        // Exact division
        if (rem == 0)
            return ans;

        ans += ".";

        // Store remainder and its position
        unordered_map<long long, int> mp;

        while (rem != 0) {

            // Repeating part found
            if (mp.find(rem) != mp.end()) {
                int pos = mp[rem];

                ans.insert(pos, "(");
                ans += ")";

                return ans;
            }

            // Store current remainder
            mp[rem] = ans.length();

            // Long division
            rem *= 10;

            ans += to_string(rem / den);

            rem %= den;
        }

        return ans;
    }
};