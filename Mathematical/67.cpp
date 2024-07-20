class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());        
        int maxLen = max(a.size(), b.size());
        for (int i = 0; i < maxLen; ++i) {
            int digitA = (i < a.size()) ? a[i] - '0' : 0;
            int digitB = (i < b.size()) ? b[i] - '0' : 0;
            int total = digitA + digitB + carry;
            res = char((total % 2) + '0') + res;
            carry = total / 2;
        }        
        if (carry) {
            res = '1' + res;
        }        
        return res;
    }
};