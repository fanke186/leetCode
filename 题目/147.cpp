#include <vector>

using namespace std;


// ***********************************************
// 对链表进行插入排序。
// ***********************************************

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


// 新建一个链表，表头结点为dump，用来存放已排序的元素
// 依次将源链表的结点取出，并插入到新链表中有序的位置
// 注：这个方法不是inplace的
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dump(0);
        ListNode* cur = head;
        while (cur != nullptr) {
            // 保存下一个要处理的结点
            ListNode* nextNode = cur->next;
            // 寻找合适的插入位置, 并插入
            ListNode* pos = &dump;
            while (pos->next != nullptr && pos->next->val < cur->val) { // 慢在这一步，每次都要判断是否到达末尾
                pos = pos->next;
            }
            ListNode* temp = pos->next;
            pos->next = cur;
            cur->next = temp;
            // 继续处理下一个
            cur = nextNode;
        }
        return dump.next;
    }
};

// inplace的方法
// 添加dump结点，以便在head前面插入结点
// 用lastSorted指向已排序的最后一个元素
// 初始状态下，lastSorted=head，cur=head->next，即默认已经插入了一个元素
// 比较lastSorted和cur值的大小，
//          若 <= ，则直接将cur作为新的lastSorted即可
//          若 >  ，则说明cur值在已排序的值区间内，找到合适的位置，插入即可，更新lastSorted为cur->next
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode dump(0);
        dump.next = head;
        ListNode* lastSorted = head;
        ListNode* cur = head->next;
        while (cur != nullptr) {
            // cur值大于已排序的最大，直接添加到末尾即可
            if (lastSorted->val <= cur->val) {
                lastSorted = lastSorted->next;
            } else { // 寻找合适的插入位置插入，cur值小于已排序的最大，肯定会落在已排序的区间内
                ListNode* pos = &dump;
                while (pos->next->val <= cur->val) {
                    pos = pos->next;
                }
                lastSorted->next = cur->next;
                cur->next = pos->next;
                pos->next = cur;
            }
            // 继续处理下一个
            cur = lastSorted->next;
        }
        return dump.next;
    }
};
