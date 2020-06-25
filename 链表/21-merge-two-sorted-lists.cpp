/*

21. 合并两个有序链表  难度：简单
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。



示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4


思路：
新建一个表头，然后两个链表哪个小就指向谁。遍历完一个链表后，剩下的链表添加到链表尾。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *root = new ListNode(-1);
        ListNode *head = root;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val <= l2 -> val)
            {
                root -> next = l1;
                root = root -> next;
                l1 = l1 -> next;
            }
            else
            {
                root -> next = l2;
                root = root -> next;
                l2 = l2 -> next;
            }
        }
        while(l1 != NULL)
        {
            root -> next = l1;
            root = root -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL)
        {
            root -> next = l2;
            root = root -> next;
            l2 = l2 -> next;
        }
        return head -> next;
    }
};


