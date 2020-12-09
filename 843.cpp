#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    
    bool backtrack(vector<int>& numbers, string S, int len, int idx, long long sum, int prev) {
        // 边界
        if (idx == len && numbers.size() >= 3) {
            return true;
        }

        long long cur = 0; // 当前选择的数
        for (int i = idx; i < len; ++i) {
            if (i > idx && S[idx] == '0') // 以0开头，长度大于等于2
                break;
        
            cur = cur * 10 + S[i] - '0'; // 计算当前数字
            if (cur > INT_MAX) // 数字超大，剪枝
                break;
            if (numbers.size() >= 2) { // 有两个以上数字，要求斐波那契性质
                if (cur < sum) // 太小了，检查下一个数
                    continue;
                else if (cur > sum) // 数字大了，剪枝
                    break;
            }
            numbers.push_back(cur); // 合适，push_back
            if (backtrack(numbers, S, len, i+1, prev+cur, cur))
                return true;
            numbers.pop_back(); // 走到这步说明，cur选择不合适，撤销选择
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) {
        vector<int> numbers;
        backtrack(numbers, S, S.length(), 0, 0, 0);
        return numbers; 
    }
};










// 回溯的一个模版
void backtrack("原始参数") {
    if ("递归终止条件") {
        // 一些操作
        return;
    }

    for (int i = "循环开始的参数"; i < "循环中止的参数"; ++i) {
        // 一些操作

        // 做选择

        // 递归
        backtrack("新参数");

        // 一些操作
        // 撤销选择
    }
}

bool backtrack(vector<int> numbers, string S, int len, int idx) {
    if (numbers.size() >= 3 && idx == len) {
        return true;
    }

    long long cur = 0;
    for (int i = idx; idx < len; ++i) {
        if (S[idx] == '0' && i > idx)
            break;
        
        cur = cur * 10 + S[i] - '0';
        if (cur > INT_MAX)
            break;
        if (numbers.size() >= 2) {
            int temp = number.back():
            numbers.pop_back();
            long long sumLast2 = numbers.back() + temp;
            number.push_back(temp);
            
            if (cur < sumLast2)
                continue;
            else if (cur > sumLast2)
                break;
        }
        numbers.push_back(cur);
        if (backtrack(numbers, S, len, i+1))
            return true;
        numbes.pop_back();
    }
    return false;
}