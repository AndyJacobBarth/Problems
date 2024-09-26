class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nums_length = nums.size();
        int k = 0;
        for (int i = 0; i < nums_length; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};