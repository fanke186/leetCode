#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// O(n), O(1)
// 从小到大考虑不同的数，用cnt记录当前数x的个数
// 当前数x，前一个数prev
// 用三个变量保存以prev结尾的子序列数目：
//      dp1保存长度为1的；
//      dp2保存长度为2的；
//      dp3保存长度>=3的；初始化都为0
// 对于当前数的个数cnt，它有以下几个去处(按优先级从上往下,因为要求子序列长度最小为3)
//      1.用来将dp1/2子序列连接成dp2/3子序列(若cnt不够则返回false)；
//      2.用来延续dp3子序列的长度(1剩的)；
//      3.作为新起dp1子序列的首元素(2剩的)；
// 更新dp1/2/3的策略：
//      1.dp1,prev结尾的dp1在这步必须清零,否则就是断链,更新值为cnt用剩的数目
//      2.dp2,prev结尾的dp1在这步必须清零,否则就是断链,更新值一定为dp1
//      3.dp3,prev结尾的dp3更新为以x结尾的dp3(即被延续的dp3),更新值为min(dp3, left)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int i = 0;
        while (i < n) {
            // 找出当前数x的个数cnt
            int start = i;
            int x = nums[i];
            while (i < n && nums[i] == x)
                ++i;
            int cnt = i - start;

            // 如果 x!=prev+1，则一定无法连接起来
            if (start > 0 && x != nums[start-1] + 1) {
                if (dp1 + dp2 > 0) // 存在断链
                    return false;
                else { // 长度都达到了3或以上，则从当前位置开始cnt个长度为1的子序列
                    dp1 = cnt;
                    dp2 = dp3 = 0;
                }
            } else { // 否则就正常处理：
                if (dp1 + dp2 > cnt) // 没有足够的数目连接dp1到dp2，dp2到dp3，会断链
                    return false;
                int left = cnt - dp1 - dp2; // 连接dp1/2后剩余的可以用来连接dp3
                int keep = min(dp3, left); // 连接完dp3还有多就以x新起子序列
                dp3 = keep + dp2; // 注意顺序
                dp2 = dp1;
                dp1 = left - keep;
            }
        }
        return dp1 == 0 && dp2 ==0;
    }
};




// O(nlogn), O(n)
// 用一个哈希表记录<int, 小根堆>记录当前以int结尾的子序列长度
// 遍历一遍
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> my_map;
        for (int& num : nums) {
            if (my_map.find(num) == my_map.end()) // 当前数不在map中
                my_map[num] = priority_queue<int, vector<int>, greater<int>>();
            if (my_map.find(num-1) != my_map.end()) { // 前置数在map中
                int prevLen = my_map[num-1].top();
                my_map[num-1].pop();
                if (my_map[num-1].empty())
                    my_map.erase(num-1);
                my_map[num].push(prevLen + 1);
            } else // 前置数不在map中，说明都被更新为以x结尾了
                my_map[num].push(1);
        }
        // 检查map中是否还存在长度小于3的子序列
        for (auto it = my_map.begin(); it != my_map.end(); ++it)
            if (it->second.top() < 3)
                return false;
        return true;
    }
};