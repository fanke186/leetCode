#include <vector>

using namespace std;

class NumMatrix {
public:
// sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + num[i][j]
    vector<vector<int>> sumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sumMatrix.resize(m);
        for (auto& row : sumMatrix) {
            row.resize(n);
        }

        sumMatrix[0][0] = matrix[0][0];
        for (int j = 1; j < n; ++j) {
            sumMatrix[0][j] = sumMatrix[0][j-1] + matrix[0][j]; 
        }
        for (int i = 1; i < m; ++i) {
            sumMatrix[i][0] = sumMatrix[i-1][0] + matrix[i][0]; 
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                sumMatrix[i][j] = sumMatrix[i-1][j] + sumMatrix[i][j-1] - sumMatrix[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2][col2] - sumMatrix[max(row1-1, 0)][col2] - sumMatrix[row2][max(col1-1,0)] + sumMatrix[max(row1-1,0)][max(col1-1,0)];

    }
};

/*
写法优化：
将sumMatrix的size定义成m+1行n+1列,
这样可以避免额外处理row1=0和col1=0的情况，类似数组下标的哨兵机制
*/
class NumMatrix {
public:
// sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + num[i][j]
    vector<vector<int>> sumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sumMatrix.resize(m+1, vector<int>(n+1));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    sumMatrix[i+1][j+1] = sumMatrix[i][j+1] + sumMatrix[i+1][j] - sumMatrix[i][j] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2+1][col2+1] - sumMatrix[row1][col2+1] - sumMatrix[row2+1][col1] + sumMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */