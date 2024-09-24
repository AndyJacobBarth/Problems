class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto iter = digits.end() - 1;
        while (*iter == 9) {
            *iter = 0;
            if (iter == digits.begin()) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            iter--;
        }
        (*iter)++;
        return digits;
    }
};