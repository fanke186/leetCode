#include <iostream>
#include <queue>

using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// 广度优先算法(BFS)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            cnt++;
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        return cnt;
    }
};


// 二分法，利用完全二叉树的性质
// 根节点记0层
// 首先一直向左找孩子，直到nullptr，这样可找到树的高度
// 在最后一层找最后一个结点，该结点序号在 2^h 和 2^(h+1)-1 之间
// 用二分法查找，exist函数用来找是否存在序号为k的某结点

// exist函数
//      如果第k个结点在第h层，则k的二进制表示有(h+1)位，其中最高位为1，
//      剩余各位从高到低表示从根节点到这个结点的路径，0表示选择左孩子，
//      1表示选择右孩子。
//      有了这个基础，就可以得到第k个结点对应的路径，并判断该结点是否存在
class Solution {
public:
    // 位运算，与二叉树的结合
    bool exist(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // 求得树高
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        // 
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exist(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

