/*
19. ɾ������ĵ�����N���ڵ�   �Ѷȣ���
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����

������ n ��֤����Ч�ġ�

���ף�

���ܳ���ʹ��һ��ɨ��ʵ����


˼·��
�趨����ָ�룬����ǰ���ָ������n��Ȼ����ͬ���ߣ����������ָ������ָ����Ҫɾ���Ľ�㡣

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


