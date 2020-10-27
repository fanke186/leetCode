#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 二叉树遍历

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// 递归
class Solution {
public:
    void preOrder(TreeNode* t){
        if (t == nullptr)
            return;
        ret.push_back(t->val);
        preOrder(t->left);
        preOrder(t->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ret;
    }
private:
    vector<int> ret;
};

// 迭代
// 显示维护栈
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        if (root == nullptr)
            return ret;
        
        TreeNode* curNode = root;
        while (!s.empty() || curNode != nullptr){
            while (curNode != nullptr){
                ret.push_back(curNode->val);
                s.push(curNode);
                curNode = curNode->left;
            }
            curNode = s.top();
            s.pop();
            curNode = curNode->right;

        }
        return ret;
    }
};

