#include <string>

using namespace std;

// 


// 穷举所有是O(n2),判断需要O(n)，那么暴力就是O(n3)
class Solution {
public:
    // 复杂度O(n)
    bool isHuiwen(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n-i-1]) {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        for (int len = s.length(); len >= 1; len--) {
            for (int i = 0; i + len < s.length() + 1; i++) {
                if (isHuiwen(s.substr(i, len))) {
                    return s.substr(i, len);
                }
            }
        }
        return "";
    }
};


// 动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }

        int dp[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        // 记录当前的最长回文子串
        int maxLen = 1;
        int beginIdx = 0;
        // 只需要填对角线以上的半个矩阵
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] == s[j] && j - i < 3) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                }
                if (dp[i][j] && j-i+1 > maxLen) {
                    maxLen = j - i + 1;
                    beginIdx = i;
                }
            }
        }
        return s.substr(beginIdx, maxLen);
    }
};

