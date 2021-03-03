#include <vector>

using namespace std;

// 库函数
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for (int i = 0; i <=num; ++i) {
            ret.push_back(__builtin_popcount(i));
        }
        return ret;
    }
};

// 按位与 x &= x-1
// 可以将x的二进制表示的最后一个1变成0
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for (int i = 0; i <=num; ++i) {
            ret.push_back(ones(i));
        }
        return ret;
    }

    int ones(int n) {
        int cnt = 0;
        while (n > 0) {
            n &= n-1;
            cnt++;
        }
        return cnt;
    }
};


// 动态规划
// 性质：正整数y是2的整数次幂，当且仅当y&(y-1)==0；
// 最高有效位数：考虑数x，将其最高位的1取出来，其他位取0，所得到的数记为y；如5-->4,7-->4;
// 考虑数x：ones[x] = ones[x-y] + 1;
// 对于[0, num]区间，从小到大取数，不断更新最高有效数即可；
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1);
        int highestBit = 0;
        for (int i = 1; i <= num; ++i) {
            if ((i & (i-1)) == 0) {
                highestBit = i;
            }
            ret[i] = ret[i - highestBit] + 1;
        }
        return ret;
    }
};