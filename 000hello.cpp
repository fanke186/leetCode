#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){  
    string s1 = "abc123abcd";
    string s2 = "23";

    // 设置s1为短的那个
    if (s1.length() > s2.length())
        s1.swap(s2);
    cout << "s1:" << s1 << '\n';
    cout << "s2:" << s2 << '\n';

    while (!s1.empty()){
        if (s2.find(s1) != -1){
            cout << "最大公共子串为:" << s1;
            return 0;
        }
        s1.erase(s1.length()-1);
    }
    cout << "不存在！";


    return 0;
        
}
   