/*

23. �ϲ�K����������  �Ѷȣ�����
�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�

ʾ��:

����:
[
  1->4->5,
  1->3->4,
  2->6
]
���: 1->1->2->3->4->4->5->6


˼·1��
��򵥵ķ�����˳�������ÿ�������ϲ������պϲ���һ���������

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
    ListNode* merge2Lists(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head = new ListNode(-1);
        ListNode *result = head;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val <= l2 -> val)
            {
                result -> next = l1;
                result = result -> next;
                l1 = l1 -> next;
            }
            else
            {
                result -> next = l2;
                result = result -> next;
                l2 = l2 -> next;
            }
        }

        while(l1 != NULL)
        {
            result -> next = l1;
            result = result -> next;
            l1 = l1 -> next;
        }
        while(l2 != NULL)
        {
            result -> next = l2;
            result = result -> next;
            l2 = l2 -> next;
        }

        return head -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode *KLists = NULL;
        for(int i = 0; i < lists.size(); i++)
        {
            KLists = merge2Lists(KLists, lists[i]);
        }
        return KLists;
    }
};

/*
���ε�˼��
- ��k��������Բ�ÿһ�Խ��кϲ�
- ��һ�ֺϲ��� k�������Ϊk/2����Ȼ����k/4 k/8����
- �ظ���һ���̣�ֱ�����ǵõ�������������
*/


class Solution {
public:
    ListNode* merge2Lists(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head = new ListNode(-1);
        ListNode *result = head;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val <= l2 -> val)
            {
                result -> next = l1;
                result = result -> next;
                l1 = l1 -> next;
            }
            else
            {
                result -> next = l2;
                result = result -> next;
                l2 = l2 -> next;
            }
        }

        while(l1 != NULL)
        {
            result -> next = l1;
            result = result -> next;
            l1 = l1 -> next;
        }
        while(l2 != NULL)
        {
            result -> next = l2;
            result = result -> next;
            l2 = l2 -> next;
        }

        return head -> next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        if(l == r) return lists[l];
        if(l > r) return nullptr;
        int mid = (l + r) / 2;
        return merge2Lists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};



