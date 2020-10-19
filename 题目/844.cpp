#include <iostream>
#include <stack>

using namespace std;

// 数组直接操作：很慢
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

// 利用双指针
// 空间复杂度为O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {

    }
};