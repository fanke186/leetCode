#include <iostream>
#include <vector>

using namespace std;

// ******************************************
// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠
// （如果有必要的话，可以合并区间）
// 如 输入：[[1,3],[6,9]]  [2,5]
//    输出：[[1,5],[6,9]]
// ******************************************

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        // 记录是否存在重叠
        int flag = 0;
        for (auto& interval : intervals) {
            if (!flag) {
                // 在左边
                if (newInterval[1] < interval[0]) {
                    ret.push_back(newInterval);
                    ret.push_back(interval);
                    flag = 1;
                } 
                // 在右边
                else if (newInterval[0] > interval[1]) {
                    ret.push_back(interval);
                }
                // 重叠
                else {
                    newInterval[0] = min(newInterval[0], interval[0]);
                    newInterval[1] = max(newInterval[1], interval[1]);
                }
            }
            else
                ret.push_back(interval);
        }
        if (!flag)
            ret.push_back(newInterval);
        return ret;
    }
};
