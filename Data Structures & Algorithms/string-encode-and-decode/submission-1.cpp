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
        return code;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        
        while (s.size() > 0) {
            auto pos = s.find("#");
            int len = stoi(s.substr(0, pos));
            string sub = s.substr(pos + 1, len);
            s = s.substr(pos + len + 1);
            strs.push_back(sub);
        }

        return strs; 
    }
};

// 代码问题
// 🔴 重要：O(n²) 的 decode
// cpps = s.substr(pos + len + 1);  // 每次都创建新字符串并赋值
// 每次循环都在截断并重新赋值整个字符串，累计下来是 O(n²)

// 🟡 小细节
// 空字符串初始化冗余
// string code 即可，默认就是空
// 字符 vs 字符串查找
// s.find('#') 略微高效，避免构造临时 string
// 空判断语义
// while (!s.empty()) 更地道

