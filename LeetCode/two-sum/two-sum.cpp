class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsLength = nums.size();
        unordered_map<int, int> hashMap;
        for (int i = 0; i < numsLength; i++) {
                int complement = target - nums[i];

                auto iterator = hashMap.find(complement);
                if (iterator != hashMap.end()) {
                    return {i, hashMap[complement]};
                }
                else {
                    hashMap[nums[i]] = i;
                }
        }
        return {};
    }
};