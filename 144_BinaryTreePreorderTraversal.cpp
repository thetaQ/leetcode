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
    void preorderTraversal(vector<int>& result, TreeNode *root)
    {
        if(root == NULL)
            return;
        result.push_back(root->val);
        preorderTraversal(result, root->left);
        preorderTraversal(result, root->right);
    }
    
    vector<int> preorderTraversal(TreeNode * root)
    {
        vector<int> result;
        preorderTraversal(result, root);
        return result;
    }
};