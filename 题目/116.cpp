#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ***********
// 给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
// 如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
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
        if (root == nullptr)
            return root;

        queue<Node*> q;
        q.push(root);

        // 层序遍历
        // 每次while就是一层结点
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                // 取出队首元素
                Node* curNode = q.front();
                q.pop();
                // 设置next指针
                if (i < n - 1)
                    curNode->next = q.front();
                // 
                if(curNode->left != nullptr)
                    q.push(curNode->left);
                if(curNode->right != nullptr)
                    q.push(curNode->right); 
            }
        }
        return root;
    }
};


// 递归写法
// 功能：连接两个给定的结点
// 边界：到空指针
class Solution {
public:
    void conNode(Node* cur, Node* next){
        if (cur == nullptr)
            return;
        cur->next = next;
        conNode(cur->left, cur->right);
        conNode(cur->right, cur->next == nullptr ? nullptr : cur->next->left);
    }
    Node* connect(Node* root) {
        conNode(root, nullptr);
        return root;
    }
};
