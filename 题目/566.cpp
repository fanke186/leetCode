#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (r*c != m*n) {
            return nums;
        }
        // 一共有m*n个元素
        // 分别转换到m行n列和r行c列，如下
        vector<vector<int>> ret(r, vector<int>(c));
        for (int no = 0; no < m*n; ++no) {
            ret[no / c][no % c] = nums[no / n][no % n];
        }
        return ret;
    }
};