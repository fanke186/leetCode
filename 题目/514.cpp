#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

// 自由之路
// **********************************************************
// 给定一个字符串 ring，表示刻在外环上的编码；
// 给定另一个字符串 key，表示需要拼写的关键词,输出能够拼写关键词中所有字符的最少步数。
// 最初，ring 的第一个字符与12:00方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在12:00方向对齐
// 然后按下中心按钮，以此逐个拼写完 key 中的所有字符。
// 旋转 ring 拼出 key 字符 key[i] 的阶段中：
// 您可以将 ring 顺时针或逆时针旋转一个位置，计为1步。
// 旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
// 如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。
// 按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。
// **********************************************************

// 当前key的下标为i, 表示当前需要拼出的字符,
// 当前ring的下标为j, 表示ring[j]在12:00方向,
// 有两种情况, 一是key[i]==ring[j],按下button就好,一步
//		      二是不等, 一直逆时针转直到相等,步数记cnt1,
//					   或是一直顺时针转直到相等,步数记cnt2,
//					   选择cnt1与cnt2的小者,按下button



// dp[i][j]记录当前在12:00方向的为ring[j], 为拼出key[0...i]字符, 所需要的最少步数
// 转移方程：
//      dp[i][j] = min(dp[i-1][k] + min(abs(j-k),n-abs(j-k)) + 1
//          (k∈pos[key[i-1]])
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n1 = key.length(), n2 = ring.length();
        // pos[i]表示ring中字符等于 'a'+i 的下标集合
        // 统计ring出现的字符
        vector<vector<int>> pos(26);
        for (int i = 0; i < n2; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }
        // DP, 0x3f3f3f3f为无穷大
        int dp[n1][n2];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        // 自底向上的底
        for (auto& i : pos[key[0] - 'a']) {
            dp[0][i] = min(i, n2 - i) + 1;
        }
        // 计算其他部分
        for (int i = 1; i < n1; i++) {
            for (auto& j : pos[key[i] - 'a']) {
                for (auto& k : pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + min(abs(j-k), n2-abs(j-k)) + 1);
                }
            }
        }
        // min_element(first,end,cmp) 或者 min_element
        // 返回容器中最小值和最大值的指针,
        // first, end指定范围, cmp为可选参数,指定比较方法
        return *min_element(dp[n1 - 1], dp[n1 - 1] + n2);
    }
};

// dp数组退化到一维
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n1 = key.length(), n2 = ring.length();
        // pos[i]表示ring中字符等于 'a'+i 的下标集合
        // 统计ring出现的字符
        vector<vector<int>> pos(26);
        for (int i = 0; i < n2; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }
        // DP, 0x3f3f3f3f为无穷大
        int dp[n2];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        // 自底向上的底
        for (auto& i : pos[key[0] - 'a']) {
            dp[i] = min(i, n2 - i) + 1;
        }
        // 计算其他部分
        int temp[n2];
        for (int i = 1; i < n1; i++) {
            memset(temp, 0x3f3f3f3f, sizeof(temp));
            for (auto& j : pos[key[i] - 'a']) {
                for (auto& k : pos[key[i - 1] - 'a']) {
                    temp[j] = min(temp[j], dp[k] + min(abs(j-k), n2-abs(j-k)) + 1);
                }
            }
            memcpy(dp, temp, sizeof(dp));
        }
        // min_element(first,end,cmp) 或者 min_element
        // 返回容器中最小值和最大值的指针,
        // first, end指定范围, cmp为可选参数,指定比较方法
        return *min_element(dp, dp + n2);
    }
};