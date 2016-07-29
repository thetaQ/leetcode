#include <iostream>
#include <vector>
#include <stack>
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

    vector<int> preorderTraversal_iteratively(TreeNode *root)
    {
        if(root == NULL)
            return vector<int>();
        stack<TreeNode *> s;
        TreeNode *p = root;
        vector<int> result;
        while(p || !s.empty())
        {
            while(p != NULL)
            {
                result.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if(!s.empty())
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return result;
    }
};