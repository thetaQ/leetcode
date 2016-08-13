#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }


class Solution {
public:
    
    inline int abs(int a, int b)
    {
        return (a) > (b) ? (a)-(b) : (b) - (a);    
    }
    
    //求二叉树的最大深度
    int deepth(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        return max(deepth(root->left), deepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if(root == NULL)
            return true;
        
        int left_deepth = deepth(root->left);
        int right_deepth = deepth(root->right);
        if(abs(left_deepth, right_deepth) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);        
    }


    int check_and_get(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int left_height = check_and_get(root->left);
        if(left_height == -1)
            return -1;
        int right_height = check_and_get(root->right);
        if(right_height == -1)
            return -1;
        if(left_height - right_height > 1 || left_height - right_height < -1)
            return -1;
        return max(left_height, right_height) + 1;
    }
    
    bool isBalanced_2(TreeNode* root)
    {
        if(check_and_get(root) == -1)
            return false;
        return true;
    }
};