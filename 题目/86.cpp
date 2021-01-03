#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *prev = head, *cur = head, *newHead = head;
        ListNode dummy(-1);
        ListNode *lessPrev = &dummy;
        while (cur) {
            if (cur->val < x) {
                lessPrev->next = cur;
                lessPrev = lessPrev->next;

                ListNode* temp = cur->next;
                if (prev == cur) { // 说明是首结点
                    prev = temp;
                    newHead = temp;
                } else { // 不是首结点
                    prev->next = temp;
                }
                cur->next = nullptr;
                cur = temp;
            } else {
                if (prev != cur) {
                    prev = prev->next;
                }
                cur = cur->next;
            }
        }
        lessPrev->next = newHead;
        return dummy.next;
    }
};