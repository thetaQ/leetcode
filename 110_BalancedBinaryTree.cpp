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
};