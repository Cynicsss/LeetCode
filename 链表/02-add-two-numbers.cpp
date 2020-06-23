/*
2. �������
�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807




˼·1��

�����Ƚ϶̵�������ĩβ����ʹ��������������ȣ���һ��һ��Ԫ�ض�����ӣ����ǽ�λ��

��������Ҫ���ǲο�����ͷ��Ϊ-1�ļ��ɡ�

��ȡ������������Ӧ�ĳ���
�ڽ϶̵�����ĩβ����
������ӿ��ǽ�λ

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

˼·2��
�����벹�㣬������Ϊ������sum(����ÿ��λ�ĺ͵Ľ��)���ϣ����ǽ�λ��
 ���ַ�������
*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);//��Ž��������
        ListNode* h=head;//�ƶ�ָ��
        int sum=0;//ÿ��λ�ļӺͽ��
        bool carry=false;//��λ��־
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
