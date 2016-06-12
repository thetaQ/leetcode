#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return true;
        //first, we find middle node, and reverse front half of list
        ListNode *fast = head, *slow = head;
        ListNode *slow_prev = NULL, *slow_next = NULL;
        ListNode *left, *right;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow_next = slow->next;
            slow->next = slow_prev;
            slow_prev = slow;
            slow = slow_next;
        }
        if(fast == NULL)//even
        {
            left = slow_prev;
            right = slow;
        } 
        else if(fast->next == NULL) //odd
        {
            left = slow_prev;
            right = slow->next;
        }
        while(left != NULL && right != NULL)
        {
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        if(left != NULL || right != NULL)
            return false;
        return true;
    }
};