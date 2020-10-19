#include <iostream>
#include <unordered_set>

using namespace std;

// **********
// 环形链表2
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// **********

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


// hash表
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while (head != nullptr){
            if (visited.count(head))
                return head;
            visited.insert(head);
        }
        return NULL;
    }
};
*/

// 指针法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr){
            slow = slow->next;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;

            if (slow == fast){
                ListNode *p = head;
                while (p != slow){
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};