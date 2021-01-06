#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<unordered_set<string>> parties;
        unordered_map<string, double> element_value;
        // 划分party
        for (int i = 0; i < equations.size(); ++i) {
            int isNewParty = 1;
            for (int j = 0; j < parties.size(); ++j) {
                if (parties[j].count(equations[i][0]) || parties[j].count(equations[i][1])) {
                    parties[j].insert(equations[i][0]);
                    parties[j].insert(equations[i][1]);
                    isNewParty = 0;
                }
            }
            if (isNewParty == 1) {
                parties.push_back({equations[i][0], equations[i][1]});
            }
        }
        for (int j = 1; j < parties.size(); ++j) {
            unordered_set<string> inter, u;
            // 交集
            set_intersection(parties[j-1].begin(), parties[j-1].end(), 
                            parties[j].begin(), parties[j].end(), inserter(inter, inter.begin()));
            if (!inter.empty()) {
                set_union(parties[j-1].begin(), parties[j-1].end(), 
                            parties[j].begin(), parties[j].end(), inserter(u, u.begin()));
                parties.erase(parties.begin() + j - 1);
                parties.erase(parties.begin() + j);
                parties.push_back(u);
                j--;
            }
        }
        // 求值
        for (int i = 0; i < equations.size(); ++i) {            
            // 某个party的第一个式子
            if (!element_value.count(equations[i][0]) && !element_value.count(equations[i][1])) {
                element_value.emplace(make_pair(equations[i][1], 1.0));
                element_value.emplace(make_pair(equations[i][0], values[i]));
            } else { // party其他的式子
                if (element_value.count(equations[i][0])) { // 除数 = 被除数 / 商
                    element_value.emplace(make_pair(equations[i][1], element_value[equations[i][0]] / values[i]));
                } else { // 被除数 = 除数 * 商
                    element_value.emplace(make_pair(equations[i][0], element_value[equations[i][1]] * values[i]));
                }
            }
        }

        // 表达式求值
        vector<double> res;
        for (int i = 0; i < queries.size(); ++i) {
            int isSameParty = 0;
            for (int j = 0; j < parties.size(); ++j) {
                if (parties[j].count(queries[i][0]) && parties[j].count(queries[i][1])) {
                    isSameParty = 1;
                    res.push_back(element_value[queries[i][0]] / element_value[queries[i][1]]);
                    break;
                }
            }
            if (!isSameParty) {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;

        int n = equations.size();
        for (int i = 0; i < n; i++) {
            if (variables.find(equations[i][0]) == variables.end()) {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end()) {
                variables[equations[i][1]] = nvars++;
            }
        }

        // 对于每个点，存储其直接连接到的所有点及对应的权值
        vector<vector<pair<int, double>>> edges(nvars);
        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            edges[va].push_back(make_pair(vb, values[i]));
            edges[vb].push_back(make_pair(va, 1.0 / values[i]));
        }

        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
                int ia = variables[q[0]], ib = variables[q[1]];
                if (ia == ib) {
                    result = 1.0;
                } else {
                    queue<int> points;
                    points.push(ia);
                    vector<double> ratios(nvars, -1.0);
                    ratios[ia] = 1.0;

                    while (!points.empty() && ratios[ib] < 0) {
                        int x = points.front();
                        points.pop();

                        for (const auto [y, val] : edges[x]) {
                            if (ratios[y] < 0) {
                                ratios[y] = ratios[x] * val;
                                points.push(y);
                            }
                        }
                    }
                    result = ratios[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};
