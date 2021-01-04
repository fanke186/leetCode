
using namespace std;

// 常规递归方法
class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

// DP法
class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        // f(n) = f(n-1) + f(n-2)
        int cur = 0, s1 = 1, s2 = 0;
        for (int i = 2; i <= n; ++i) {
            cur = s1 + s2;
            s2 = s1;
            s1 = cur;
        }
        return cur;
    }
};