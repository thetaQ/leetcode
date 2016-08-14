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

    //二叉树中序遍历的方式
    TreeNode * kthSmallest(TreeNode *root, int k, int &cur_index)
    {
        if(root == NULL)
            return NULL;
        TreeNode *left = kthSmallest(root->left, k, cur_index);
        if(left != NULL)
            return left;
        cur_index ++;
        if(cur_index == k)
            return root;
        return kthSmallest(root->right, k, cur_index);
    }
    
    
    int kthSmallest(TreeNode* root, int k)
    {
        int cur_index = 0;
        TreeNode *target = kthSmallest(root, k, cur_index);
        return target->val;
    }
};