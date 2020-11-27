#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// O(n^2)
// 枚举A,B的二元组合,用sumAB来保存二元组的和
// 存储为一个哈希表,key_value 为 二元组之和_cnt
// 枚举C,D的二元组合,若其和的负数出现在哈希表的key值,则满足条件,ret += cnt
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ret = 0;
        unordered_map<int, int> sumAB; // 在不要求有序的时候，使用unodered_map效率会更高
        for (int& numA : A) {
            for (int& numB : B) {
                int curABSum = numA + numB;
                sumAB[curABSum]++; // 这行和下面三行作用一样，默认插入值为(curABSum, 0)
                // if (sumAB.count(curABSum))
                //     sumAB[curABSum]++;
                // else 
                //     sumAB.emplace(curABSum, 0);
            }
        }
        for (int& numC : C) {
            for (int& numD : D) {
                int curCDSum = numC + numD;
                if (sumAB.count(-curCDSum))
                    ret += sumAB[-curCDSum];
            }
        }
        return ret;
    }
};