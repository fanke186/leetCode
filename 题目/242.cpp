#include <string>
#include <unordered_map>

// *****************************************************
// 给定两个字符串 s 和 t ,
// 编写一个函数来判断 t 是否是 s 的字母异位词。
// *****************************************************

using namespace  std;

// 只包含26个小写字母
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        for (char c : t) {
            cnt[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                return false;
            }
        }
        return true;
    }
};

// 若包含的字符集是unicode
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cnt;
        // 插入s的字符
        for (char c : s) {
            if (!cnt.count(c)) {
                cnt.emplace(c, 1);
            } else {
                cnt[c]++;
            }
        }
        // 删去t中有的
        for (char c : t) {
            if (!cnt.count(c)) {
                return false;
            } else {
                cnt[c]--;
                if (cnt[c] == 0) {
                    cnt.erase(c);
                }
            }
        }
        // 检查是否还有
        if (!cnt.empty()) {
            return false;
        }
        return true;
    }
};
