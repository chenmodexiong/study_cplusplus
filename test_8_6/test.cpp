

//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//示例 1：
//输入：digits = "23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//示例 2：
//输入：digits = ""
//输出：[]
//示例 3：
//输入：digits = "2"
//输出：["a", "b", "c"]

class Solution {
    string strA[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    void Combine(string digits, int level, string combineStr, vector<string>& v)
    {
        if (level == digits.size())
        {
            v.push_back(combineStr);
            return;
        }
        int num = digits[level] - '0';
        string str = strA[num];
        for (size_t i = 0; i < str.size(); ++i) {
            Combine(digits, level + 1, combineStr + str[i], v);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> v;
        if (digits.empty())
            return v;
        Combine(digits, 0, "", v);
        return v;
    }
};