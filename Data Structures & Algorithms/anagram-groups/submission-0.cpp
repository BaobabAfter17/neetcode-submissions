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
        array<int, 26> count = {};
        for (char c : s) {
            ++count[c - 'a'];
        }

        string chars = "";
        for (int i = 0; i < 26; ++i) {
            chars += to_string(count[i]);
            chars += "#";
        }
        return chars;
    }
};
