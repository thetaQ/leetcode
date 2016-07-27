#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一
    bool isValidBST(TreeNode *root)
    {
        if(root == NULL)
            return true;
            
        if(!isValidBST(root->left))
            return false;
            
        if(last_printed != NULL && root->val <= last_printed->val)
            return false;
        last_printed = root;
        
        if(!isValidBST(root->right))
            return false;
        return true;
    }
private:
    TreeNode *last_printed = NULL; 
};

