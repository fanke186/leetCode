#include <iostream>

using namespace std;

// *********
// 删除给定链表的倒数第n个结点，返回其头结点；
// （给定的输入一定是有效的）
// *********


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // 快慢指针，一次遍历
 // 链表常用操作：引入哑巴结点（dummy），使其指向head，以避免对头结点的特殊判断。
 // 快慢指针：定义两个指针fast, slow，一次遍历分两个循环完成，
 //          第一个循环让fast往后走n，slow不动，循环完成后slow在fast的前面n位置，
 //          第二个循环让slow和fast同步往后走，直到fast走到链表末尾，此时slow正好指向倒数第n个结点。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0, head);
        ListNode *slow = &dummy, *fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};