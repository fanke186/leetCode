#include <iostream>
#include <stack>

using namespace std;

// 方法一
// 数组直接操作
class Solution {
public:
    string backspace(string s){
        int i = 0;
        while (i < s.length()){
            if (s[i] == '#'){
                if (i > 0){
                    s.erase(i-1, 2);
                    i--;
                }
                else s.erase(i, 1);
            }
        }
        return s;
    }

    bool backspaceCompare(string S, string T) {
        cout << backspace(S) << endl;
        cout << backspace(T) << endl;
        return backspace(S) == backspace(T);
    }
};

// 方法二
// 利用栈, cpp的string也有类似栈的操作；
// 对栈：
//      1.当前字符若是'#'：pop栈顶(判断栈非空）；
//      2.当前字符若非'#'：push入栈；
class Solution {
public:
    string backSpace(string s){
        string ret;
        for (char ch : s){
            if(ch != '#')
                ret.push_back(ch);
            else if (!ret.empty())
                ret.pop_back();
        }
        return ret;
    }
    bool backspaceCompare(string S, string T) {
        return backSpace(S) == backSpace(T);
    }
};


// 方法三
// 利用双指针
// 空间复杂度为O(1)
// 处理步骤：
//      当前字符是'#'：cnt++,继续往前;
//      当前字符非'#'：如果cnt > 0,则cnt--(模拟删除),继续往前;
//                    如果cnt <= 0,则代表这个字符是不会被删除的，跳出循环;
// 查看是否有数组已经走到头了;
// 比较保留下来的字符是否相等;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length()-1, j = T.length()-1;
        int cntS = 0, cntT = 0;
        // 每次最外层while，都是消除一个连续的 “k个字母 + k个# ” 块
        while (1){
            // 处理S
            while (i >= 0) {
                if (S[i] == '#') cntS++;
                else {
                    if (cntS > 0) cntS--;
                    else break;
                }
                i--;
            }
            // 处理T
            while (j >= 0) {
                if (T[j] == '#') cntT++;
                else {
                    if (cntT > 0) cntT--;
                    else break;
                }
                j--;
            }
            // S 或 T走到头了
            if (i < 0 || j < 0) break;
            // 比较不等则返回 false
            if (S[i] != T[j]) return false;
            i--;
            j--;
        }
        // ST中的一个先走到头
        if (i == -1 && j == -1)
            return true;
        // ST同时走到头
        return false;
    }
};