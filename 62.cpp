#include <vector>

using namespace std;


// 排列组合方法
class Solution {
public:
    // 这个碰到大数不好使
    int uniquePaths(int m, int n) {
        int numR = n - 1, numD = m - 1;
        int sum = numR + numD;
        long long ret = 1;
        for (int i = 1; i <= numR; ++i) {
            ret = ret * (sum - i + 1) / i;
        }
        return ret;
    }

    // 这个好使
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }  
};


// 动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1]; // 左上角(1,1),右下角(m,n)
        for (int i = 1; i <= m; ++i)
            dp[i][n] = 1;
        for (int j = 1; j <= n; ++j)
            dp[m][j] = 1;

        for (int i = m - 1; i >= 1; --i)
            for (int j = n - 1; j >= 1; --j)
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
        return dp[1][1];
    }
};