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


// 自顶向下的归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortMerge(head, nullptr);
    }

    ListNode* sortMerge(ListNode* head, ListNode* tail) {
        // 递归边界：链表节点数小于等于1
        // 即链表为空或者只有一个元素的时候，不需要再进行拆分和排序
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        // 寻找链表的中点
        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        // 递归调用 与 归并
        return merge(sortMerge(head, mid), sortMerge(mid, tail));
    }


    // 合并两个有序链表
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dump = new ListNode(0);
        ListNode* temp = dump, *cur1 = head1, *cur2 = head2;
        // 插入list1和list2当前的较小者
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                temp->next = cur1;
                cur1 = cur1->next;
            } else {
                temp->next = cur2;
                cur2 = cur2->next;
            }
            temp = temp->next;
        }
        // 将剩余的部分连接上
        if (cur1 != nullptr) {
            temp->next = cur1;
        } else if (cur2 != nullptr) {
            temp->next = cur2;
        }
        return dump->next;
    }
};

// 自底向上的归并排序
class Solution {
public:
    // 合并两个有序链表
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dump = new ListNode(0);
        ListNode* temp = dump, *cur1 = head1, *cur2 = head2;
        // 插入list1和list2当前的较小者
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                temp->next = cur1;
                cur1 = cur1->next;
            } else {
                temp->next = cur2;
                cur2 = cur2->next;
            }
            temp = temp->next;
        }
        // 将剩余的部分连接上
        if (cur1 != nullptr) {
            temp->next = cur1;
        } else if (cur2 != nullptr) {
            temp->next = cur2;
        }
        return dump->next;
    }


    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int n = 0; //记录链表结点总数
        ListNode* node = head;
        while (node != nullptr) {
            n++;
            node = node->next;
        }

        ListNode *dump = new ListNode(0, head);
        for (int subLength = 1; subLength < n; subLength <<= 1) {
            ListNode *pre = dump, *cur = dump->next;
            while (cur != nullptr) {
                ListNode *head1 = cur;
                for (int i = 1; i < subLength && cur->next != nullptr; i++) {
                    cur = cur->next;
                }

                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 1; i < subLength && cur != nullptr && cur->next != nullptr; i++) {
                    cur = cur->next;
                }

                ListNode *next = nullptr;
                if (cur != nullptr) {
                    next = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                pre->next = merged;
                while (pre->next != nullptr) {
                    pre = pre->next;
                }
                cur = next;
            } 
        }
        return dump->next;
    }
};

