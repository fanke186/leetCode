#include <string>

using namespace std;

// 计数器
class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        for (char c : t) {
            cnt[c - 'a']--;
        }
        char ret;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                ret = 'a' + i;
                break;
            }
        }
        return ret;
    }
};