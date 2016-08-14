#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    int countNodes(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left_height = 0, right_height = 0;
        TreeNode *p = root;
        while(p != NULL)
        {
            left_height ++;
            p = p->left;
        }
        p = root;
        while(p != NULL)
        {
            right_height ++;
            p = p->right;
        }
        
        if(left_height == right_height)
        {
            return  (1 << left_height) - 1;
        }
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};