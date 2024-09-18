class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        // We checked that x >= 0, so unsigned can be used
        unsigned int temp = x, comparison = 0;
        while (temp > 0) {
            comparison *= 10;
            comparison += temp - (temp / 10) * 10;
            temp /= 10;
        }
        if (x == comparison)
            return true;
        else
            return false;
    }
};