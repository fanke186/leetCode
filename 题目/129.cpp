#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


// 二叉树的每个结点都代表一个数字，
// 这个数字=父节点的值*10 + 当前结点的值，
// 用DFS或者BFS求出每个结点对应的数字，
// 将叶子结点代表的数字加起来即可得到结果。

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// DFS
class Solution {
public:
    int dfs(TreeNode*t, int preSum) {
        // 递归边界
        if (t == nullptr) return 0;
        int sum = preSum * 10 + t->val;
        // 是叶子结点
        if (t->left == nullptr && t->right == nullptr)
            return sum;
        else 
            return dfs(t->left, sum) + dfs(t->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};


// BFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        queue<TreeNode*> nodeQ;
        queue<int> numQ;

        nodeQ.push(root);
        numQ.push(root->val);

        while (!nodeQ.empty()) {
            TreeNode* node = nodeQ.front();
            int num = numQ.front();
            nodeQ.pop();
            numQ.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            if (left == nullptr && right == nullptr) {
                sum += num;
            } else {
                if (left != nullptr) {
                    nodeQ.push(left);
                    numQ.push(num * 10 + left->val);
                }
                if (right != nullptr) {
                    nodeQ.push(right);
                    numQ.push(num * 10 + right->val);
                }
            }
        }
        return sum;
    }
};



