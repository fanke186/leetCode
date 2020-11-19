#include <vector>
#include <algorithm>

using namespace std;


// 直接按要求重载sort函数
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                ret.push_back({i, j});
            }
        }
        sort(ret.begin(), ret.end(), [=](vector<int>& a, vector<int>& b) {
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        return ret;
    }
};


// 距离的桶排序
// 其实辅助数组的大小退化到了计数排序的 max-min
// 最大距离由两部分：行最大+列最大组成
// 创建 maxDis+1 个桶,
// 桶i中存放:距离等于i的所有下标组合
// 依次将桶中元素放置到返回结果即可
class Solution {
public:
    int getDis(int r1, int c1, int r2, int c2) {
        return abs(r1-r2) + abs(c1-c2);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // 最大距离
        int maxDis = max(r0, R-1-r0) + max(c0, C-1-c0);
        // 每个距离一个桶
        vector<vector<vector<int>>> buckets(maxDis + 1);

        // 放到相应的桶
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int dis = getDis(i, j, r0, c0);
                vector<int> curDot = {i, j};
                buckets[dis].push_back(move(curDot));
            }
        }

        // 放到返回结果
        vector<vector<int>> ret;
        for (int i = 0; i < buckets.size(); i++) {
            for (auto& item : buckets[i]) {
                ret.push_back(item);
            }
        }
        return ret;
    }
};

