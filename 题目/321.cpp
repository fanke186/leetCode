#include <vector>

using namespace std;


// 总体策略为：
// 在nums1和nums2中一共选择k个数，保持相对顺序，要求组成的数最大；
// 分化简化问题：
// 在nums1中选择len1个数,在nums2中选择len2个数，这样问题就变成了在单个数组进行处理；
// 假设我们能解决上面这个问题，那么原问题的解就等于两个子问题的归并；
// 一共有k种情况，len1 = 1...min(k, length1), len2 = k-len2
// 求出总共k个归并的解，比较后返回最大的即为原问题的解；
class Solution {
public:
    // 假定nums1和nums2是代表数的两个数组
    // 此方法返回的是维持两个数组元素相对顺序的二者的组合数
    // 有两个特殊情况需要注意：
    // 1.nums1[i]于nums2[j]相等，这样的话要往后比较到出现不相等才能判断应该插入谁
    // 2.第一种情况一直向后比较，达到了数组边界，这里也要做处理
    //      如:5 , 5 6 7 二者，必须指定选择后者的5，才能出现5675，不然最大只是5567
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> ret;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            int i_temp = i, j_temp = j;
            while (i_temp < nums1.size() && j_temp < nums2.size() && nums1[i_temp] == nums2[j_temp]) {
                i_temp++;
                j_temp++;
            }
            if (i_temp < nums1.size() && j_temp < nums2.size()) { // 两个都没到头
                if(nums1[i_temp] > nums2[j_temp])
                    ret.push_back(nums1[i++]);
                else 
                    ret.push_back(nums2[j++]);
            } else { // 至少有一方到头了
                if (i_temp < nums1.size()) // nums1没到头
                    ret.push_back(nums1[i++]);
                else // nums2没到头,或者两个都到头了
                    ret.push_back(nums2[j++]);
            }
        }
        for (; i < nums1.size(); i++) ret.push_back(nums1[i]);
        for (; j < nums2.size(); j++) ret.push_back(nums2[j]);
        return ret;
    }

    // 保留nums数组中的k个数字(数字的相对顺序不变)，使得组成的数最大
    // 
    // 保留k个数字，也即去除size()-k个数字，本函数可以转化为402题
    // 贪心策略：尽量在高位的时候代替数字，因为这样才能在高位得到尽可能大的数字；
    // 下面是一样的注释：
    // 维护一个单调栈(栈底到栈顶单调不增)来保存所保留的数字，从左往右遍历nums，对于当前的数字nums[i]，
    //      若toRemove不为零 且 栈不空 且 nums[i]大于栈顶元素，则将栈顶pop，toRemove--
    //      否则直接将nums[i]入栈
    // 这样得到的栈内容的由栈底算起的前k个内容就是所求，再之后的是不满足大于栈顶的后续所有元素(一共有toRemove个)；
    vector<int> remainKMax(vector<int> nums, int k) {
        vector<int> ret;
        int toRemove = nums.size() - k;
        for (int i = 0; i < nums.size(); i++) {
            while (toRemove && !ret.empty() && ret.back() < nums[i]) {
                ret.pop_back();
                toRemove--;
            }
            ret.push_back(nums[i]);
        }
        return {ret.begin(), ret.begin() + k};
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1, len2;
        vector<int> ret(k, 0), temp;
        for (len1 = 0; len1 <= min(k, (int)nums1.size()); len1++) {
            len2 = k - len1;
            if (len2 <= nums2.size())
                ret = max(ret, merge(remainKMax(nums1, len1), remainKMax(nums2, len2)));
        }
        return ret;
    }
};