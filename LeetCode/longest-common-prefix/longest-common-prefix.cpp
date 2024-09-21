class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strs_length = strs.size();
        string lcp = "";
        int first_str_length = strs[0].length();
        for (int i = 0; i < first_str_length; i++) {
            for (int j = 1; j < strs_length; j++) {
                if (i >= strs[j].length())
                    return lcp;
                if (strs[0][i] != strs[j][i]) {
                    return lcp;
                }
            }
                lcp += strs[0][i];
        }
        return lcp;
    }
};