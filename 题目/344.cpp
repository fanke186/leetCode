#include <iostream>
#include <vector>
using namespace std;

// ***********
// 反转字符串
// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
// ***********


class Solution {
public:
    void swap(vector<char>& s, int i, int j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};