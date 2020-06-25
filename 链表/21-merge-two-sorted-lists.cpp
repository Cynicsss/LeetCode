/*

21. �ϲ�������������  �Ѷȣ���
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�



ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4


˼·��
�½�һ����ͷ��Ȼ�����������ĸ�С��ָ��˭��������һ�������ʣ�µ�������ӵ�����β��

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


