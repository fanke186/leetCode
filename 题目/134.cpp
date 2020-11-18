#include <vector>

using namespace std;


// 将每一个点作为起点, 看它是否满足作为起点走完一圈
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        for (int i = 0; i < n; i++) {
            // 尝试以idx=i作为起点, 用cur记录目前走到的站点
            int cur = i;
            while (1) {
                tank += gas[cur]; // 到站补充油箱
                if (tank < cost[cur]) {
                    break;
                } else {
                    tank -= cost[cur]; 
                    cur = (cur+1) % n; // 花费相应的油向前开一站
                    if (cur == i) {
                        return i;
                    }
                }
            }

        }
        return -1;
    }
};


// 将所有站点从前往后遍历一遍
// 用oil来记录油的盈余, 初始为0, 更新式为 oil += gas[i] - cost[i]
// 首先明确一点,要有解就必须满足：sum(gas) >= sum(cost), 
//        这点可以通过让检查最后的oil是否大于0来验证
// 假设有解(题目限定若有解则解唯一), 这个解所在的位置就是oil盈余最低的时候,
//        否则如果在其他的位置开始, 在走到最低位置的时必定油不足
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int oil = 0;
        int minOil = 0x3f3f3f3f;
        int minIdx = 0;

        for (int i = 0; i < n; i++) {
            oil = oil + gas[i] - cost[i];
            if (oil < minOil) {
                minOil = oil;
                minIdx = i;
            }
        }
        return oil < 0 ? -1 : (minIdx + 1) % n;
    }
};