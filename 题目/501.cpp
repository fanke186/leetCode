#include <iostream>
#include <vector>

using namespace std;

// **********
// 给定一个有相同值的二叉搜索树（BST），
// 找出 BST 中的所有众数（出现频率最高的元素）.
// **********


// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

// 1 2 2 3 4 6 6 6 8 8 8 
class Solution {
public:
    int count = 0;
    int maxcount = 0;
    int pre = -9999;

    void inOrder(TreeNode* t, vector<int>* a){
        if(t == NULL)
            return;
        inOrder(t->left, a);
        // 当前结点
        if(pre == t->val)
            count++;
        else{
            count = 1;
            pre = t->val;
        }
        
        if(count >= maxcount){
            if(count > maxcount)
                a->clear();
            a->push_back(t->val);
            maxcount = count;
        }

        inOrder(t->right, a);        
    }



    vector<int> findMode(TreeNode* root) {
        vector<int> a;
        inOrder(root, &a);
        return a;

    }
};