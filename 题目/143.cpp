#include <iostream>
#include <stack>
#include <vector>


using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 时间O(n), 空间O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> v;
        // 转换为数组，方便进行随机访问
        ListNode* node = head;
        while (node){
            v.push_back(node);
            node = node->next;
        }
        // 重新构造链表
        int i = 0, j = v.size()-1;
        while (i < j){
            v[i]->next = v[j];
            i++;
            if (i == j) break;
            v[j]->next = v[i];
            j--;
        }
        // 置链表尾的 next 为 null
        v[i]->next = nullptr;
    }
};


// 时间O(n), 空间O(1)
// 三步策略：
//      1.找到链表的中点;
//      2.将后半部分链表逆序;
//      3.合并两半链表;
class Solution {
public:
    // 找给定链表的中点
    ListNode* findMid(ListNode* head){
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 反转给定链表
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr, *cur = head, *nextNode;
        while (cur != nullptr){
            nextNode = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextNode;
        }
        return pre;
    }
    // 交错合并两个链表
    void mergeList(ListNode* l1, ListNode* l2){
        ListNode *next1, *next2;
        while (l1 && l2){
            next1 = l1->next;
            next2 = l2->next;

            l1->next = l2;
            l1 = next1;
            l2->next = l1;
            l2 = next2;
        }
    }

    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* midPoint = findMid(head);
        ListNode* head2 = midPoint->next;
        midPoint->next = nullptr;   // 截断成两个链表
        head2 = reverseList(head2);
        mergeList(head, head2);
    }
};