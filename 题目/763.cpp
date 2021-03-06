#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//###########################################################
// 显然一个字母的第一次出现和最后出现应被划分在同个片段;
// 首先,遍历字符串得到每 一个字母的最后出现下标;
// 然后遍历字符串找当前片段, 由start=0, end=0开始,
// 对当前遍历到的字母有两个情况:
//      先设置end=max(end, last.at(S[i])),
//      1.若end = i,i为当前遍历的下标,表示找到了一个片段
//      2.若end != i, i++继续遍历
//###########################################################

// 时间O(n), 空间O(1)
// 把hash表改成数组，在时间和空间上可以再减少
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // 找到每个字母的最大下标
        unordered_map<char, int> endIdx;
        for (int i=0; i<S.length(); i++){
            if(!endIdx.count(S[i]))
                endIdx.insert(pair<char, int>(S[i], i));
            else 
                endIdx.at(S[i]) = max(endIdx.at(S[i]), i);
        }
        //
        int curStart = 0, curEnd = 0;
        vector<int> ret;
        for (int j=0; j<S.length(); j++){
            curEnd = max(curEnd, endIdx.at(S[j]));
            if (j == curEnd){
                ret.push_back(curEnd - curStart + 1);
                curStart = curEnd + 1;
            }
        }
        return ret;
    }
};


// 把hash表改成数组
// 大幅减少时间(非数量级)，小幅减少空间
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // 找到每个字母的最大下标
        int last[26] = {0};
        for (int i=0; i<S.length(); i++)
            last[S[i] - 'a'] = i;
        //
        int curStart = 0, curEnd = 0;
        vector<int> ret;
        for (int j=0; j<S.length(); j++){
            curEnd = max(curEnd, last[S[j] - 'a']);
            if (j == curEnd){
                ret.push_back(curEnd - curStart + 1);
                curStart = curEnd + 1;
            }
        }
        return ret;
    }
};