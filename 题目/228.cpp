#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        int n = nums.size();
        vector<string> ret;
        string curInterval;

        // 初始化
        int end = nums[0];
        curInterval.append(to_string(nums[0]));
        // 依次处理区间
        for (int i = 1; i < n; i++) {
            if (nums[i] == end + 1) { // 连续数字
                end = nums[i];
            } else { // 出现断裂
                if (end != stoi(curInterval)) { // 区间是否只含一个数
                    curInterval.append("->" + to_string(end));
                }
                ret.push_back(curInterval);
                curInterval.clear();
                curInterval.append(to_string(nums[i]));
                end = nums[i];
            }
        }
        // 处理最后一个区间
        if (end != stoi(curInterval)) {
            curInterval.append("->" + to_string(end));
        }
        ret.push_back(curInterval);

        return ret;
    }
};