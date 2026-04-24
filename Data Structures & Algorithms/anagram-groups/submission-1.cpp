class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // char_cnt : vector<string>
        unordered_map<string, vector<string>> str_group;
        for (const string& s : strs) {
            const string chars = getCharCount(s);
            str_group[chars].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [_, group] : str_group) {
            res.push_back(group);
        }
        return res;
    }

    string getCharCount(const string& s) {
        string ss = s;
        sort(ss.begin(), ss.end());
        return ss;
    }
};
