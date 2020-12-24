#include <vector>

using namespace std;


// 按照题意，两个相邻的小朋友AB(左右有序)，
//      若B高于A，则B糖果多于A，称为左性质
//      若A高于B，则A糖果多于B，称为右性质
// 若一个小朋友序列同时满足左右性质，就是题目所要求的
// 先给每个小朋友都分一个糖果
// 用left和right分别记录两个方向的遍历
// 1.从左到右遍历，若某小朋友rating大于其左边小朋友rating，就分配更多一个
// 2.从右到左遍历，若某小朋友rating大于其右边小朋友rating，就分配更多一个
// 这样每个小朋友就有两个糖果数，分别是左和右，取较大者就可以同时满足左右性质
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 0;
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        // 从左到右，和从右到左
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
            if (ratings[n-1-i] > ratings[n-i]) {
                right[n-1-i] = right[n-i] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            ret += max(left[i], right[i]);
        }
        return ret;
    }
};