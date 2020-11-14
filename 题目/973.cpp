#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// ****************************************************
// 我们有一个由平面上的点组成的列表 points,
// 需要从中找出 K 个距离原点 (0, 0) 最近的点
// ****************************************************



// 维护maxIdx的代价太大
// 会很慢, 用大根堆数据结构可以解决这个问题
class Solution {
public:
    int getDis(vector<int> point) {
        return point[0]*point[0] + point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;
        int maxIdx = 0;
        // 初始K个
        for (int i = 0; i < K; i++) {
            ret.push_back(points[i]);
            if (getDis(ret[i]) > getDis(ret[maxIdx]))
                maxIdx = i;
        }
        // 从第K+1开始比较
        for (int i = K; i < points.size(); i++) {
            if (getDis(points[i]) < getDis(ret[maxIdx])) {
                ret[maxIdx] = points[i];
                for (int j = 0; j < K; j++) {
                    if (getDis(ret[j]) > getDis(ret[maxIdx]))
                        maxIdx = j;
                }
            }
        }
        return ret;
    }
};


// 用lambda表达式重载sort函数
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [](const vector<int> u, const vector<int> v) {
            return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        };
        sort(points.begin(), points.end(), cmp);
        return {points.begin(), points.begin() + K};
    }
};


// 大根堆
// priority_queue 提供常数时间的（默认）最大元素查找, 对数代价的插入与释出
class Solution {
public:
    int getDis(const vector<int> p) {
        return p[0]*p[0] + p[1]*p[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // 记录：(距离, 序号)
        priority_queue<pair<int, int>> q;
        // 先插入K个
        for (int i = 0; i < K; i++)
            q.emplace(getDis(points[i]), i);
        // 从第K+1个开始比较
        int n = points.size();
        for (int i = K; i < n; i++) {
            int curDis = getDis(points[i]);
            if (curDis < q.top().first) {
                q.pop();
                q.emplace(curDis, i);
            }
        }
        // 插入结果
        vector<vector<int>> ret;
        for (int i = 0; i < K; i++) {
            ret.emplace_back(points[q.top().second]);
            q.pop();
        }
        return ret;
    }
};




// 以下是介绍优先队列(priority_queue)的例子
// 三个参数依次为：
//              1.存储的元素类型
//              2.用于存储元素的底层的容器类型
//              3.严格弱序比较类型cmp
// 注意：在弱序中, 若其第一参数 "先于" 其第二参数, 则返回 true
//       但因为 priority_queue 首先输出"最大"元素，故"先来"的元素实际上最后输出。
//          (这里的"最大","先来"都是在比较方法cmp下的)
template<typename T> void print_queue(T& q) {
	while (!q.empty()) {
		cout << q.top() << '\t';
		q.pop();	
	}
	cout << endl;
}

int main() {
	priority_queue<int> qMax;
	priority_queue<int, vector<int>, greater<int>> qMin;
	for (int i : {1, 2, 3, 4, 5}) {
		qMax.emplace(i);
		qMin.emplace(i);
	}
	print_queue(qMax);
	print_queue(qMin);
	return 0;
}
