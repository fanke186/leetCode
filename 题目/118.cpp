#include <vector>

using namespace std;

// 杨辉三角



// 模拟
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> prev = {1};
        ret.push_back(prev);
        for (int i = 2; i <= numRows; ++i) {
            vector<int> cur = {};
            for (int j = 0; j < i; ++j) {
                if (j-1 < 0)
                    cur.push_back(prev[j]);
                else if (j > prev.size())
                    cur.push_back(prev[j-1]);
                else
                    cur.push_back(prev[j-1] + prev[j]);
            }
            ret.push_back(cur);
            prev = cur;
        }
        return ret;
    }
};


// 数学解法，用多了两个点：第n行有n+1个元素；每行的第一个和最后一个都是1
// 其实也一样，只是少了些判断，对prev的越界访问只会出现在两端的1
// 在计算之前直接将它们置为1，就不用再判断了
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};