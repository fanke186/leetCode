#include <iostream>

using namespace std;

// *********
// 交换相邻结点
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
// *********


// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 // 迭代解法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head, *pre = head;
        ListNode* temp;
        int flag = 1;
        if (head && head->next)
            head = head->next;
        while(cur && cur->next){
            // 交换pair
            temp = cur->next;
            cur->next = temp ->next;
            temp->next = cur;
            // 到下一个pair
            cur = cur->next;
            // 连接前面的结点(要求不是第一对)
            if (!flag){
                pre->next = temp;
                pre = pre->next->next;
            }
            flag = 0;
        }
        return head;
    }
};

// 优化迭代解法:更清晰，显式声明node1与node2为当前要交换的pair
// 且引入了一个哑巴结点，对比于上面，统一了算法流程（避免判断）；
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* hHead = new ListNode(0);
		hHead->next = head;
        ListNode* cur = hHead;
        while(cur->next && cur->next->next){
			// 找到目前的pair
            ListNode* node1 = cur->next;
			ListNode* node2 = cur->next->next;
            // 交换目前的pair
            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1;			
        }
        return hHead->next;
    }
};


// 递归解法
class Solution {
public:
    // 递归函数的作用：
    //      输入某链表的头结点，返回其前两个结点交换后的新链表的心头头结点；
    // 边界条件：输入的链表长度为 0 或 1；
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};