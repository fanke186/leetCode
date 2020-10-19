#include <iostream>
#include <vector>
using namespace std;


// ***********
// 让二叉树的每个结点的next指针指向同层的右边结点；
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
// 如果找不到下一个右侧节点，则将 next 指针设置为 NULL。是
// ***********




// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> curLayer;
        vector<Node*> nextLayer;
        
        curLayer.push_back(root);
        while(!curLayer.empty()){
            // 设置当前层结点的next指针
            for(int i = 0; i < curLayer.size()-1; i++)
                curLayer[i]->next = curLayer[i+1];
            // 获取下一层结点到 nextLayer
            for(int i = 0; i < curLayer.size() && curLayer[i] != nullptr; i++){
                if(curLayer[i]->left)
                    nextLayer.push_back(curLayer[i]->left);
                if(curLayer[i]->right)
                    nextLayer.push_back(curLayer[i]->right);
            }
            // 设置好层结点
            curLayer.swap(nextLayer);
            nextLayer.clear();            
        }
        return root;
    }
};