#include <vector>
using namespace std;

// 返回小于n的素数个数,其中n为非负整数


// 枚举法，但是只检查前(2, sqrt(n))
class Solution {
public:
    bool isPrime(int x) {
        for (int i = 2; i *  i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    int countPrimes(int n) {
        int ret = 0;
        for (int num = 2; num < n; num++)
            ret += isPrime(num);
        return ret;
    }
};

// 埃氏筛
// 用数组isPrime记录每一个数是否是质数,初始都置为1
// 遍历数组，若是质数，则将它的倍数都置为0(不是质数)
// 正确性：
//      不会将质数标记成合数：因为初始都是置为1
//      不会将合数标记为质数：因为合数必定是若干个小于它的质数乘积，肯定会在之前被置0
// 改进：对于当前遍历到的质数x，应该从x*x(即x倍)开始标记，
//       因为小于x倍的在之前就已经被标记过了
//       比如遍历到5的时候，合数15在遍历到3的时候已被标记，可以直接从5*5开始
class Solution {
public:
    int countPrimes(int n) {
        int ret = 0;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == 1) {
                ret++;
                if ((long long)i*i < n)
                    for (int j = i*i; j < n; j+=i)
                        isPrime[j] = 0;
            }
        }
        return ret;
    }
};

// 线性筛：在埃氏筛的基础上改进
// 考虑埃氏筛的一个情况：
//      遍历到质数3和5的时候，30会被重复标记两次，改进是为了让一个合数只被标记一次
// 增加一个数组primes，保存当前遍历过的质数集合
// 合数标记行为不再仅当x是质数的时候才进行，而是每一个x都进行；
// 标记行为：
//      不再是标记x的倍数为合数，而是标记x与prims集合的数的乘积为合数，
//      且在发现x能被prims_i整除的时候提前结束标记，因为下一个合数x*prims_(i+1)一定会在
//      后续遍历到 x / prims_i * prims_(i+1)的时候被标记，这样保证了单个素数只被标记一次(最小质因数)
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1), primes;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i] == 1)
                primes.push_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};