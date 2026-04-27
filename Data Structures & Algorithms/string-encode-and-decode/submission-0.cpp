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
        string code = "";
        for (const string& s : strs) {
            code += to_string(s.size());
            code += "#";
            code += s;
        }
        // 5#Hello6#World
        return code;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        
        while (s.size() > 0) {
            auto pos = s.find("#");
            // if (pos == string::npos) {
            //     return strs;
            // }
            int len = stoi(s.substr(0, pos));
            string sub = s.substr(pos + 1, len); // "Hello"
            s = s.substr(pos + len + 1);
            strs.push_back(sub);  // ["Hello", ]
        }

        return strs; 
    }
};
