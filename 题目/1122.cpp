#include <vector>

using namespace std;

// ********************************************************
// 给你两个数组，arr1 和 arr2，
// arr2 中的元素各不相同,
// arr2 中的每个元素都出现在 arr1 中,
// 对 arr1 中的元素进行排序,
//     使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。
//     未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
// ********************************************************

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ret;
        // c[i]存放的是arr1中 = i 的元素个数
        int c[1001] = {0};
        for (int i = 0; i < arr1.size(); i++) {
            c[arr1[i]]++;
        }
        // 将arr1中存在的arr2元素按序插入ret
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < c[arr2[i]]; j++) {
                ret.emplace_back(arr2[i]);
            }
            c[arr2[i]] = 0;
        }
        // 将arr1中非arr2元素插入ret
        for (int i = 0; i < 1001; i++) {
            while (c[i] != 0) {
                ret.emplace_back(i);
                c[i]--;
            }
        }
        return ret;
    }
};