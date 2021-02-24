#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        // 水平翻转
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= n - 1 - j; j++) {
                swap(A[i][j], A[i][n - 1 - j]);
                A[i][j] = A[i][j] == 0;
                if (j != n - 1 - j) {
                    A[i][n - 1 - j] = A[i][n - 1 - j] == 0;
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
                A[i][j] = A[i][j] == 0;
            }
        }
        return A;
    }
};