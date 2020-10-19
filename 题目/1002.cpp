#include <iostream>
#include <vector>
#include <string>

using namespace std;


//***********
// 寻找公共字符
// 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
// 例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
//***********

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minFreq(26, 101);
        vector<string> ret;
        // 每个字符串
        for (int i = 0; i < A.size(); i++){
            // 置 curFreq 为全0
            vector<int> curFreq(26, 0);
            // 当前字符串的每个字符
            for (int j = 0; j < A[i].length(); j++)
                curFreq[A[i][j]-'a']++;
            // 维护 minFreq 数组
            for (int i = 0; i < 26; i++)
                minFreq[i] = min(minFreq[i], curFreq[i]);

        }
        for (int i = 0; i < minFreq.size(); i++){
            //cout << minFreq[i];
            while (minFreq[i]){
                string letter(1, char('a' + i));
                ret.push_back(letter);
                minFreq[i]--;
            }
        }
        return ret;
    }
};