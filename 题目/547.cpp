#include <vector>
#include <unordered_set>

using namespace std;


// DFS大法好
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int nCities, int i) {
        for (int j = 0; j < nCities; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                dfs(isConnected, visited, nCities, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int nCities = isConnected.size();
        vector<int> visited(nCities, 0);
        int nProvinces = 0;
        for (int i = 0; i < nCities; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, nCities, i);
                nProvinces++;
            }
        }
        return nProvinces;
    }
};