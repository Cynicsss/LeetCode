/*

23. 合并K个排序链表  难度：困难
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6


思路1：
最简单的方法，顺序遍历，每次两两合并，最终合并成一个大的链表

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
分治的思想
- 将k个链表配对并每一对进行合并
- 第一轮合并后 k个链表变为k/2个，然后是k/4 k/8个等
- 重复这一过程，直到我们得到最终有序链表
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



