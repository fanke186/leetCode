#include <string>

using namespace std;


// 递归边界：长度小于k
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) {
            return 0;
        }
        // 统计当前字符串的字频
        int cnt[26] = {0};
        for (char ch : s) {
            cnt[ch-'a']++;
        }
        int idx = 0;
        // 找到第一个出现次数小于K的字符的下标
        while (idx < s.size() && cnt[s[idx] - 'a'] >= k) {
            idx++;
        }
        // 整个字符串都“合法”
        if (idx == s.size()) {
            return idx;
        }
        int left = longestSubstring(s.substr(0, idx), k);
        // 越过所有不满足条件的字符
        while (idx < s.size() && cnt[s[idx] - 'a'] < k) {
            idx++;
        }
        int right = longestSubstring(s.substr(idx), k);
        return max(left, right);
    }
};