#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 定义“块”：在字符串中，以不同字母为分界点的连续字符，记为(letter, cnt)
    // 如aabbbc有三个块：(a,2), (b, 3), (c,1)
    bool isLongPressedName(string name, string typed) {
        int p = 0, q = 0;
        // 一次 while 就是块(字母，次数)
        // 不比较q与typed.length可以把typed块数小于name的情况考虑进去
        while (p < name.length() && q < typed.length()){
            int cntName = 1, cntTyped = 1;
            // 字符不相等，直接返回false
            if(name[p] != typed[q])
                return false;
            // 字符相等，继续看
            else {
                // 找name里面的此块 次数
                while (p + 1 < name.length() && name[p] == name[p+1]){
                    p++;
                    cntName++;
                }
                // 找typed里面的此块 次数
                while (q + 1 < typed.length() && typed[q] == typed[q+1]){
                    q++;
                    cntTyped++;
                }
                // 如果typed块的次数比name块少，返回false
                if (cntTyped < cntName)
                    return false;
                p++;
                q++;
            }
        }
        // name 和 typed 的块数不相等
        if (p < name.length() || q < typed.length())
            return false;
        return true;
    }
};