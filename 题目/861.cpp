#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 将行首元素不是1的每一行进行翻转
// 从第二列开始，若当前列0的数量多于1的数量，就翻转当前列
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int ret = 0, m = A.size(), n = A[0].size();
        for (int i = 0; i < m; ++i) { // 将行首元素不是1的行都翻转
            if (A[i][0] == 0)
                for (int& num : A[i])
                    num = !num;
        }
        for (int j = 0; j < n; ++j) { // 统计每一列1的数量
            int ones = 0;
            for (int i = 0; i < m; ++i)
                ones += A[i][j];
            ret += max(ones, m - ones) << (n - 1 - j);
            
        }
        return ret;
    }
};

// 原地计算，减少代码行数和一些时间空间
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int ret = 0, m = A.size(), n = A[0].size();
        for (int j = 0; j < n; ++j) {
            int ones = 0;
            for (int i = 0; i < m; ++i)
                if (A[i][0] == 0) ones += !A[i][j];
                    else ones += A[i][j];
            ret += max(ones, m - ones) << (n - 1 - j);
        }
        return ret;
    }
};


