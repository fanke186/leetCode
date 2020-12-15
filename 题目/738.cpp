#include <vector>
#include <string>
using namespace std;


// 贪心策略
// 要找到小于N的最大单增数，则要尽可能保留N的尽可能高的位，以期小于N的最大
// 记N从高到低的位分别是0,1,2,...,n
// 假设能够保留的最高位是x，则将A[0, x]保留，将A[x+1]减一，将A[x, n]都置为9即可
//
// 1.从高到低找第一个位置i，使得[0, i-1]都是单增，但[i-1, i]是单减；
// 2.从位置i往前(从低到高)，逐个将A[i-1]--，直到不再有A[i-1] > A[i]
// 3.得到一个位置j，从j往后的都置为9即可
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        // 将数字逆序存储到数组A，注意与算法描述的存储方向相反
        // A[0]存储最低位, A[n]存储最高位
        vector<int> A;
        while (N > 0) {
            A.push_back(N % 10);
            N /= 10;
        } 

        // 找到第一个单减的位置i
        int i = A.size()-2;
        while (i >= 0 && A[i] >= A[i+1]) {
            i--;
        }
        if (i >= 0) { // 否则数字N本身就是单增的
            while (i+1 < A.size() && A[i] < A[i+1]) { // 从第一次出现单减的位置往前
                A[i+1]--;
                i++;
            }
            // 算法叙述的j就是循环后i的低一位
            // 由于高位有减小，低位全置为9也满足 <= N
            for (--i; i >= 0; --i) {
                A[i] = 9;
            }
        }

        // 得到返回值
        int ret = 0;
        for (int i = A.size()-1; i >= 0; --i) {
            ret = ret * 10 + A[i];
        }
        return ret;
    }
};


// 改进版本：C++存在由int到string的转化函数
//    string = to_string(int)
//    int = stoi(string)
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int i = 1;
        while (i < strN.length() && strN[i-1] <= strN[i]) {
            i++;
        }
        if (i < strN.length()) {
            while (i > 0 && strN[i-1] > strN[i]) {
                strN[i-1]--;
                i--;
            }
            for (++i; i < strN.length(); ++ i) {
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};
