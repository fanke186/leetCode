#include <iostream>
#include <unordered_set>



using namespace std;


class Solution {
public:
    int backtrack(int n, int row, unordered_set<int>& col, 
    unordered_set<int>& dia1, unordered_set<int>& dia2){
        if (row == n)
            return 1;
        int count = 0;
        for (int i = 0; i < n; i++){
            // 在同一列
            if (col.find(i) != col.end())
                continue;
            // 在对角线1
            int d1 = row - i;
            if (dia1.find(d1) != dia1.end())
                continue;
            // 在对角线2
            int d2 = row + i;
            if (dia2.find(d2) != dia2.end())
                continue;
            // 维护集合
            col.insert(i);
            dia1.insert(d1);
            dia2.insert(d2);
            // 维护解数
            count += backtrack(n, row+1, col, dia1, dia2);
            // 回溯
            col.erase(i);
            dia1.erase(d1);
            dia2.erase(d2);
        }
    }
    int totalNQueens(int n) {
        unordered_set<int> col, dia1, dia2;
        return backtrack(n, 0, col, dia1, dia2);
    }
};