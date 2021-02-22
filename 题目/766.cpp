#include <vector>

using namespace std;


// 左上到右下对角线的条数是(m+n-1)
// 对角线的值为第一行和第一列的值
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // values已保存   
        for (int no = 0; no < m; no++) {
            for (int i = no, j = 0; i < m && j < n; i++, j++) {
                if (matrix[i][j] != matrix[no][0]) {
                    return false;
                }
            }
        }
        for (int no = 1; no < n; no++) {
            for (int i = 0, j = no; i < m && j < n; i++, j++) {
                if (matrix[i][j] != matrix[0][no]) {
                    return false;
                }
            }
        }
        return true;
    }
};

// 遍历矩阵，与左上角元素相比即可
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};