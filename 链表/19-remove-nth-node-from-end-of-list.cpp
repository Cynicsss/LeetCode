/*
19. 删除链表的倒数第N个节点   难度：简单
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？


思路：
设定两个指针，走在前面的指针先走n步然后再同步走，这样后面的指针最后会指向需要删除的结点。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return NULL;
        ListNode *front = head;
        ListNode *result = head;
        ListNode *pre;
        for(int i = 0; i < n; i++)
            front = front -> next;
        if(front == NULL) return head -> next;
        while(front != NULL)
        {
            front = front -> next;
            pre = result;
            result = result -> next;
        }
        pre -> next = result -> next;
        return head;
    }
};


