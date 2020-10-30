#include <iostream>
#include <vector>

using namespace std;


// 遍历矩阵，遇到为1的值，lands++
// 就查看其上下左右是否为1，为1就edges++
// 岛屿内相邻的边会使得周长-2
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int lands = 0;
        int edges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    lands++;
                    // 上
                    if (i-1 >= 0 && grid[i-1][j] == 1)
                        edges++;
                    // 下
                    if (i+1 < grid.size() && grid[i+1][j] == 1)
                        edges++;
                    // 左
                    if (j-1 >= 0 && grid[i][j-1] == 1)
                        edges++;
                    // 右
                    if (j+1 < grid[i].size() && grid[i][j+1] == 1)
                        edges++;
                }
            }
        }
        return lands * 4 - edges;
    }
};




// DFS
// 岛屿的周长等于
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col){
        // 走到网格边界了
        if (!(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()))
            return 1;
        // 旁边是水域，可以算作周长
        if (grid[row][col] == 0)
            return 1;
        // 已经访问过的陆地块
        if (grid[row][col] == 2)
            return 0;
        // 元素标为visited
        grid[row][col] = 2;
        // 递归调用
        return dfs(grid, row-1, col) +
            dfs(grid, row+1, col) +
            dfs(grid, row, col-1) +
            dfs(grid, row, col+1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // 找到第一块陆地
        // 因为恰有一个岛屿，可以直接return
        for (int i=0; i < grid.size(); i++){
            for (int j=0; j < grid[0].size(); j++){
                if (grid[i][j] == 1)
                    return dfs(grid, i, j);
            }
        }
        return 0;
    }
};

