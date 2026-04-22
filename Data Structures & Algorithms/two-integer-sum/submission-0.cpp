class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // save num: index in hashmap seen
        // if target - num in hashmap
        // return [index of num, index of peer]
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            const int peer = target - nums[i];
            if (seen.contains(peer)) {
                return {seen[peer], i};
            }
            seen[nums[i]] = i; // 3:0
        }
        return {};
    }
};
