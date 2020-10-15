#include <vector>
#include <iostream>
using namespace std;


// ***********
// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
// ***********

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int x, y;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 让xy分别存目标结点值，并 x<y
        x = p->val;
        y = q->val;
        if(p->val > q->val){
            y = p->val;
            x = q->val;
        }
        
        while(root != nullptr){
            // x,y都在左侧
            if(y < root->val){
                root = root->left;
                continue;
            }
            // x,y都在右侧
            if(x > root->val){
                root = root->right;
                continue;
            }
            return root;            
        }
        return nullptr;
    }
};