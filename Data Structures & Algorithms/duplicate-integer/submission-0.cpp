class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // hashmap num: appearance
        // hashset
        // []
        // [1, 2, 3, 3]
        // [1, 2, 3, 4]
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.contains(num))
                return true;
            seen.insert(num);  // [1, 2, 3]
        }
        return false;
    }
};