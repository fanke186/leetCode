#include <vector>

using namespace std;

// 从下往上是改进
// 01数组与1异或可以得到反转的结果

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        // 水平翻转同时反转
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1 - j; j++) {
                swap(A[i][j], A[i][n - 1 - j]);
                A[i][j] ^= 1;
                A[i][n - 1 - j] ^= 1;
            }
            // 奇数列的中点
            if (n % 2) {
                A[i][n/2] ^= 1;
            }
        }

        return A;
    }
};

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        // 水平翻转同时反转
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= n - 1 - j; j++) {
                swap(A[i][j], A[i][n - 1 - j]);
                A[i][j] ^= 1;
                if (j != n - 1 - j) {
                    A[i][n - 1 - j] ^= 1;
                }
            }
        }
        return A;
    }
};

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        // 水平翻转
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= n - 1 - j; j++) {
                swap(A[i][j], A[i][n - 1 - j]);
            }
        }
        // 反转
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] ^= 1;
            }
        }
        return A;
    }
};