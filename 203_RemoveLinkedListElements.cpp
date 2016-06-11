#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * removeElements(ListNode *head, int val)
    {
        ListNode *prev_head = new ListNode(-1);
        prev_head->next = head;
        ListNode *tmp = prev_head;
        while(tmp->next != NULL)
        {
            if(tmp->next->val == val)
            {
                //del tmp->next
                ListNode *del = tmp->next;
                tmp->next = del->next;
                delete del;
            }
            else
                tmp = tmp->next;
        }
        ListNode *new_head = prev_head->next;
        delete prev_head;
        return new_head;
    }
};