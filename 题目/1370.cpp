#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 桶计数
// 分析可知，对字符在s中的位置不关心，
// 每一轮先输出一个升序字符串，然后是一个降序字符串
class Solution {
public:
    string sortString(string s) {
        vector<int> cnt(26);
        for (char& ch : s) {
            cnt[ch - 'a']++;
        }

        string ret;
        while (ret.length() != s.length()) {
            // 存放升序字符串
            for (int i = 0; i < 26; i++) {
                if (cnt[i]) {
                    ret.push_back('a' + i);
                    cnt[i]--;
                }
            }
            // 存放降序字符串
            for (int i = 25; i >= 0; i--) {
                if (cnt[i]) {
                    ret.push_back('a' + i);
                    cnt[i]--;
                }
            }
        }
        return ret;
    }
};