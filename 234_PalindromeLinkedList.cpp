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

    bool isPalindromCore(ListNode *head, int length, ListNode **node)
    {
        if(head == NULL || length == 0)
        {
            *node = NULL;
            return true;
        }
        else if(length == 1)
        {
            *node = head->next;
            return true;
        }
        else if(length == 2)
        {
            *node = head->next->next;
            return head->val == head->next->val;
        }
        else
        {
            bool result = isPalindromCore(head->next, length-2, node);
            if(result == false || *node == NULL)
                return result;
            result = head->val == (*node)->val;
            *node = (*node)->next;
            return result;
        }
    }
    bool isPalindrome_2(ListNode *head)
    {
        int length = 0;
        ListNode *p = head;
        while(p != NULL)
        {
            length ++;
            p = p->next;
        }
        ListNode *node = NULL;
        return isPalindromCore(head, length, &node);
    }
};