
// ***********
// 两数相加
// 给出两个 非空 的链表用来表示两个非负的整数。
// 其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// ***********



// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;

        while(l1 || l2){
            // 防止空指针
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int tempSum = n1 + n2 + carry;
            // 如果是空表
            if (!head)
                head = tail = new ListNode(tempSum % 10);
            // 非空表，尾插
            else {
                tail->next = new ListNode(tempSum % 10);
                tail = tail->next;
            }

            carry = tempSum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        // 最高位如果有，再进一
        if(carry > 0){
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

