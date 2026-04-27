// 算法思路：长度前缀编码（Length-Prefix Encoding）
// Encode
// 对每个字符串，不直接拼接，而是先写入它的长度，再写一个固定分隔符，再写字符串内容：
// 格式：{length}#{string}
// 例如 ["hello", "wo#rld"] 编码为：
// 5#hello6#wo#rld
// Decode
// 读取时不按字符找分隔符，而是：
// 从当前位置开始，向后扫描找到第一个 #
// 取 # 之前的数字，解析为长度 n
// 从 # 后面精确读取 n 个字符，这就是一个完整的字符串
// 将指针移动到下一段，重复上述步骤
class Solution {
public:

    string encode(vector<string>& strs) {
        string code;
        for (const string& s : strs) {
            code += to_string(s.size());
            code += "#";
            code += s;
        }
        return code;
    }

    // 5#hello6#world
    vector<string> decode(string s) {
        vector<string> strs;
        
        int i = 0;
        while (i < s.size()) {
            int j = s.find('#', i); // j = 8
            int len = stoi(s.substr(i, j - i)); // 5
            string sub = s.substr(j + 1, len);  // hello
            strs.push_back(sub);    // hello, 
            i = j + 1 + len;    // 7
        }

        return strs; 
    }
};
