#include <vector>
#include <algorithm>

using namespace std;


// 这个时间也是O(nlogn)，应该是系数比较大吧
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        // 按开始坐标排序
        auto cmp = [](vector<int>& p1, vector<int>& p2){
            return p1[0] < p2[0];
        };
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i + 1 < points.size(); ++i) {
            // 与下一个有交集
            if (points[i][1] >= points[i+1][0]) {
                points[i][0] = points[i+1][0];
                points[i][1] = min(points[i][1], points[i+1][1]);
                points.erase(points.begin() + i + 1);
                i--; //再退回上一个
            }
        }
        return points.size();
    }
};


// 贪心法
// 首先射爆第一个气球(贪心：射它的最右边)，
// 再向后检查，这一箭是否能穿破下一个气球，
//      若可以，继续检查下一个气球，
//      若不可以，射下一箭，依然是射下一个气球的最右边，
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        // 按结束坐标排序
        auto cmp = [](vector<int>& p1, vector<int>& p2){
            return p1[1] < p2[1];
        };
        sort(points.begin(), points.end(), cmp);

        int pos = points[0][1];
        int ret = 1;
        for (const auto& balloon : points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ret++;
            }
        }
        return ret;
    }
};