#include <iostream>
#include <unordered_set>

using namespace std;

// **********
// 环形链表1
// 给定一个链表，如果链表中存在环，则返回 true 。 否则，返回 false 。
// **********

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
// hash表法，空间时间都是O(n)
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while (head != nullptr){
            if(visited.count(head))
                return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
*/

// 快慢指针
// 慢指针每次更新为 it->next;
// 快指针每次更新为 it->next->next;
// 慢指针从 head 开始，快指针从 head->next 开始；
// 只要快指针追上慢指针(相等)，即链表有环；
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr){
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};