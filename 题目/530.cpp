#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// **********
// 找BST的两节点值差的绝对值的最小值
// 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
// **********




//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


// 递归实现中序遍历
class Solution {
public:
    // 在中序的递归实现中，可以用pre来记录前驱结点的值
    // pre初始化为二叉树中不会存在的值；
    int minAbs = 998, pre = -998;


    void InOrder(TreeNode* t){
        if(t == nullptr)
            return;
        // 左
        if(t->left)
            InOrder(t->left);
        // 中
        if (pre == -998) {
            pre = t->val;
        } else {
            minAbs = min(minAbs, t->val - pre);
            pre = t->val;
        }
        // 右
        if(t->right)
            InOrder(t->right);
    }

    int getMinimumDifference(TreeNode* root) {
        InOrder(root);
        return minAbs;
    }
};


// 非递归（栈）实现中序遍历
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        // 在中序的递归实现中，可以用pre来记录前驱结点的值
        // pre初始化为二叉树中不会存在的值；
        int minAbs = 998, pre = -998;
        stack<TreeNode*> s;
        while (root || !s.empty()){
            if(root){
                s.push(root);
                root = root->left;
            }else{
                if(pre == -998)
                    pre = s.top()->val;
                else{
                    minAbs = min(minAbs, s.top()->val - pre);
                    pre = s.top()->val;
                }
                root = s.top()->right;
                s.pop();
            }
        }
        return minAbs;
    }
};
