#include <iostream>
#include <string>
#include <iterator>
#include <map>


using namespace std;


/*
// 双for循环
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int lenJ = J.size();
        int lenS = S.size();
        int num = 0;

        string::iterator iJ = J.begin();
        string::iterator iS = S.begin();

        for(int i = 0; i < lenJ; i++){
            for(int j = 0; j < lenS; j++){
                if(J[i] == S[j])
                    num++;
            }
        }
        return num;
    }
};
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> mapJew;
        string::iterator iJ = J.begin();
        string::iterator iS = S.begin();
        int num = 0;
        // 构造哈希表
        for(int j = 0; j < J.size(); j++)
            mapJew.insert(map<char, int>::value_type(J[j], 0));
        
        for(int i = 0; i < S.size(); i++){
            map<char, int>::iterator cur = mapJew.find(S[i]);
            // 是珠宝
            if (cur != mapJew.end()){
                cur->second += 1;
                num += 1;
            }

        }
    }
};
