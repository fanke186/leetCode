#include <iostream>

using namespace std;

//###################################################################
// 回文序列的特点：
//     1.从中间分别往左右，一直相等直到同时到头；
//     2.从头尾往中间，一直相等，直到相遇；
// 考虑到单链表向前访问存在困难，算法如下：
// 首先遍历一遍找到链表中点(快慢指针)，
// 将后半部分反转，
// 遍历对比前后两半部分的val，
//      若n为偶数，要么一直相等到底，返回T；要么其间存在不相等，返回F；
//      若n为奇数，与n为偶数在实现上一模一样；
//###################################################################




// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 找到链表的中点
    ListNode* findMid(ListNode* head){
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 反转给定链表
    ListNode* reverseList(ListNode* head){
        ListNode *pre = nullptr, *temp, *cur = head;
        while (cur != nullptr){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        ListNode* midPoint = findMid(head);
        ListNode* head2 = midPoint->next;
        midPoint->next = nullptr;
        // 反转后半部分
        ListNode* rHead2 = reverseList(head2);
        while (head && rHead2){
            if (head->val != rHead2->val)
                return false;
            head = head->next;
            rHead2 = rHead2->next;
        }
        return true;
    }
};