#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 将行首元素不是1的每一行进行翻转
// 从第二列开始，若当前列0的数量多于1的数量，就翻转当前列
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int ret = 0;
        vector<int> numbers; // 记录二进制每一位的数字
        for (int i = 0; i < A.size(); ++i) { // 将第一列都置1
            if (A[i][0] == 0)
                for (int& num : A[i])
                    num = !num;
        }
        numbers.push_back(A.size());
        for (int j = 1; j < A[0].size(); ++j) {
            int before = 0, after;
            for (int i = 0; i < A.size(); ++i)
                before += A[i][j];
            after = A.size() - before;
            numbers.push_back(max(before, after));
            // 将0多的列进行翻转
            if (after > before)
                for (int i = 0; i < A.size(); ++i)
                    A[i][j] = !A[i][j];
        }
        int n = A[0].size();
        for (int i = 0; i < n; ++i) // 计算数字
           ret += (numbers[i] << (n - i - 1));
        return ret;
    }
};

