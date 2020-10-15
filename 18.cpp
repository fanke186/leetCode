#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// **********
// 四数之和
// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
// 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等
// 找出所有满足条件且不重复的四元组。
// **********


class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.empty()) return {};
        int len = nums.size();
        // 先排序
        sort(nums.begin(), nums.end());
        // 前两个 for 循环找出所有的二元组；
        // 这两个 continue 是防止结果中出现重复的四元组；
        for(int i = 0; i < len-3; i++){
            if(i != 0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j < len-2; j++){
                if(j != i+1 && nums[j]==nums[j-1]) continue;
                cur.clear();
                cur.push_back(nums[i]);
                cur.push_back(nums[j]);
                // 找完二元组后，在剩下的连续数组(有序)中找到和为subTarget的二元组；
                // 找法是：因为有序，可以利用头尾指针，其和大于subTarget就尾指针自减，其和小于subTarget就头指针自减；
                int subTarget = target - nums[i] - nums[j];
                int head = j+1, tail = len-1;
                while(head < tail){
                    if(nums[head] + nums[tail] > subTarget)
                        tail--;
                    else if(nums[head] + nums[tail] < subTarget)
                        head++;
                    else{
                        cur.push_back(nums[head]);
                        cur.push_back(nums[tail]);
                        ret.push_back(cur);
                        // 同样的i,j(最初二元组)下还可能存在多种结果；
                        cur.pop_back();
                        cur.pop_back();
                        // 防止在同样的i, j下选到相同的四元组；
                        do{tail--;} while(head<tail && nums[tail]==nums[tail+1]);
                        do{head++;} while(head<tail && nums[head]==nums[head-1]);
                    }
                }
            }
        }
        return ret;
    }
};

