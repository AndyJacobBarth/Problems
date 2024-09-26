class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, k = 1, nums_length = nums.size();

        while (i != nums_length) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; 
                k++;
            }
            i++;
        } 
        return k;
    }
};