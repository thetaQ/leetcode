#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //方法一：迭代法
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1 != NULL || l2 != NULL || carry > 0)
        {
            int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            
            l1 = (l1 == NULL ? l1 : l1->next);
            l2 = (l2 == NULL ? l2 : l2->next);
        }
        return dummy->next;
    }

    //方法二：递归法
    ListNode* addTwoNumbersRecurisive(ListNode* l1, ListNode* l2, int carry)
    {
        if(l1 == NULL && l2 == NULL && carry == 0)
        {
            return NULL;
        }
        
        int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
        ListNode *new_node = new ListNode(sum % 10);
        carry = sum / 10;
        new_node->next = addTwoNumbersRecurisive(l1 == NULL ? l1 : l1->next, 
                                                 l2 == NULL ? l2 : l2->next, 
                                                 carry);
        return new_node;
    }
    
    ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2)
    {
        return addTwoNumbersRecurisive(l1, l2, 0);
    }
};