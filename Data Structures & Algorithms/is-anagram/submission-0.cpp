class Solution {
public:
    bool isAnagram(string s, string t) {
        // char_s array<int, 26>
        // char_t array<int, 26>
        // check if char_s == char_t
        array<int, 26> char_s{};
        array<int, 26> char_t{};
        for (char c : s) {
            ++char_s[c - 'a'];
        }
        for (char c : t) {
            ++char_t[c - 'a'];
        }

        // compare result
        for (int i = 0; i < 26; ++i) {
            if (char_s[i] != char_t[i])
                return false;
        }
        return true;
    }
};
