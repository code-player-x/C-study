//2. �������https://leetcode-cn.com/problems/add-two-numbers/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);//��Ž��������
        ListNode* h = head;//�ƶ�ָ��
        int sum = 0;//ÿ��λ�ļӺͽ��
        bool carry = false;//��λ��־
        while (l1 != NULL || l2 != NULL)
        {
            sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
                sum++;
            h->next = new ListNode(sum % 10);
            h = h->next;
            carry = sum >= 10 ? true : false;
        }
        if (carry)
        {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};

