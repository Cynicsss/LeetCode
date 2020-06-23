/*
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807




思路1：

将长度较短的链表在末尾补零使得两个连表长度相等，再一个一个元素对其相加（考虑进位）

这里最主要的是参考链表开头设为-1的技巧。

获取两个链表所对应的长度
在较短的链表末尾补零
对齐相加考虑进位

/*

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int l1_length = 1, l2_length = 1;
        ListNode *l1_head = l1;
        ListNode *l2_head = l2;
        while(l1 -> next != NULL)
        {
            l1_length++;
            l1 = l1 -> next;
        }

        while(l2 -> next != NULL)
        {
            l2_length++;
            l2 = l2 -> next;
        }

        if(l1_length < l2_length)
        {
            for(int i = 0; i < (l2_length - l1_length); i++)
            {
                l1 -> next = new ListNode(0);
                l1 = l1 -> next;
            }
        }
        else if(l1_length > l2_length)
        {
            for(int i = 0; i < (l1_length - l2_length); i++)
            {
                l2 -> next = new ListNode(0);
                l2 = l2 -> next;
            }
        }
        ListNode *l3 = new ListNode(-1);
        ListNode *l3_h = l3;
        int count = 0;
        l1 = l1_head;
        l2 = l2_head;
        while(l1 != NULL && l2 != NULL)
        {
            int sum = l1 -> val + l2 -> val + count;
            l3 -> next = new ListNode(sum % 10);
            if(sum >= 10) count = 1;
            else count = 0;
            l1 = l1 -> next;
            l2 = l2 -> next;
            l3 = l3 -> next;
        }

        if(count == 1)
            l3 -> next = new ListNode(1);
        return l3_h -> next;

    }
};


/*

思路2：
不对齐补零，若链表不为空则用sum(代表每个位的和的结果)加上，考虑进位。
 这种方法更好
*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);//存放结果的链表
        ListNode* h=head;//移动指针
        int sum=0;//每个位的加和结果
        bool carry=false;//进位标志
        while(l1!=NULL||l2!=NULL)
        {
            sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry)
                sum++;
            h->next=new ListNode(sum%10);
            h=h->next;
            carry=sum>=10?true:false;
        }
        if(carry)
        {
            h->next=new ListNode(1);
        }
        return head->next;
    }
};
