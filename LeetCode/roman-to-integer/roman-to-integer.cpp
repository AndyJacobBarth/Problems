class Solution {
public:
    int romanToInt(string s) {
        int s_length = s.length();
        int total = 0;

        unordered_map<char, int> numerals = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for (int i = 0; i < s_length; i++) {
            if (
                s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X') ||
                s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C') ||
                s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')
            ) {
                total += numerals[s[i + 1]] - numerals[s[i]];
                i++;
            }
            else
                total += numerals[s[i]];
        }
        return total;
    }
};