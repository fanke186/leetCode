#include <string>
#include <vector>

using namespace std;


// 在数num中，要求去除k个数字，使得保存下来的数字最小
// 返回的数字不能包含前导0：如 0200 -> 200
// 总体思想为：
// 维护一个单调栈(单调不减)来保存想要留存的数字
// 从左往右遍历这个数的数字，记当前数字为d:
//      如果还未去除k个数字，且栈不为空，且d大于栈顶，则pop栈顶，k--
//      不然就直接将d入栈
// 走完for循环后，栈中的倒数k个数都是多余的，因为它们是因为没法大于栈顶元素而入栈的
//      (一共要去除k个，for循环内Pop了一部分，剩下一部分需要我们手动去除)
// 然后是处理前导0的过程；
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> s;
        for (char& digit : num) {
            while (k && !s.empty() && s.back() > digit) {
                s.pop_back();
                k--;
            }
            s.push_back(digit);
        }
        while (k-- > 0)
            s.pop_back();
        
        // 去掉前导0
        string ret = "";
        bool isLeadingZero = true;
        for (auto& digit : s) {
            if (isLeadingZero && digit == '0')
                continue;
            isLeadingZero = false;
            ret += digit;
        }
        return ret == "" ? "0" : ret;
    }
};