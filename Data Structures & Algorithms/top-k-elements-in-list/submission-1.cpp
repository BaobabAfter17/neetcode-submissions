
//         Top K Frequent Elements — 最优解思路
// 这题最优解是 Bucket Sort，时间复杂度 O(n)，比用 heap 的 O(n log k) 更好。

// 核心思路
// 关键观察：一个元素的出现频率，最小是 1，最大是 n（数组长度）。所以频率的范围是有界的，可以用这个范围做桶。
// 三步走：
// 第一步 — 统计频率
// 用一个 hash map 统计每个元素出现了多少次。
// 比如 [1,1,1,2,2,3] → {1:3, 2:2, 3:1}
// 第二步 — 建桶
// 创建一个长度为 n+1 的数组，下标代表频率，值是出现该频率的所有元素。

// index 1 → [3]
// index 2 → [2]
// index 3 → [1]

// 为什么是 n+1？因为最高频率不可能超过 n，刚好可以用下标直接映射。
// 第三步 — 从高频到低频扫描桶
// 从桶的最右边（最高频率）往左遍历，依次收集元素，直到凑够 k 个为止。

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums)
            ++freq[num];

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto [num, cnt] : freq)
            bucket[cnt].push_back(num);

        vector<int> res;
        for (auto it = bucket.rbegin(); it != bucket.rend() && res.size() < k; ++it)
            res.insert(res.end(), it->begin(), it->end());

        return res;
    }
};
