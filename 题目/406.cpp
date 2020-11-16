#include <vector>
#include <algorithm>


using namespace std;

// **********************************************************************
// 假设有打乱顺序的一群人站成一个队列
// 每个人由一个整数对(h, k)表示，
//          其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 
// 编写一个算法来重建这个队列。
// **********************************************************************


// 如果k相等, 那么h小的一定在前面
// 如果h相等, 那么k小的一定在前面
//
// 排在第i个的(h_i, k_i), 说明前i-1个里面 恰有 k_i个大于等于h_i,
// 考虑先把队伍的人从矮到高排好队, 然后从矮到高依次取出一个人,
// 将他放到最终的位置i, 这个最终的位置i要求: 前i-1个位置里面仍有k_i个"空位",
// 这样就可以满足题意(因为是从矮到高取人出来放置的)
// 
// 时间O(n2)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 将people按身高从小到大排序, 若一样高的则是k大的排在后面
        auto cmp = [](const vector<int>& u, const vector<int> v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        };
        sort(people.begin(), people.end(), cmp);

        // 返回结果的向量
        int n = people.size();
        vector<vector<int>> ret(n);
        // 把每一个person放到按要求排队后的正确位置
        for (const vector<int>& person : people) {
            int empty_spaces = person[1] + 1;
            // 为这个人寻找排队后的正确位置(即目前队列中从前往后数的第ki+1个空位置)
            for (int i = 0; i < n; i++) {
                if(ret[i].empty()) {
                    empty_spaces--;
                    if (empty_spaces == 0) {
                        ret[i] = person;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};