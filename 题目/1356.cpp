#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 除二取余法
    int get(int x){
        int res = 0;
        while (x) {
            res += (x % 2);
            x /= 2;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (auto x : arr)
            bit[x] = get(x);
        // lambda表达式：允许将函数作为参数进行传递
        // c++11引进的特性
        sort(arr.begin(), arr.end(), [&](int x, int y){
            if (bit[x] < bit[y])
                return true;
            if (bit[x] > bit[y]) 
                return false;
            return x < y;
        });
        return arr;
    }
};

