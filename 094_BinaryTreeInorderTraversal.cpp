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
    void inorderTraversalCore(TreeNode *root, vector<int>& result)
    {
        if(root == NULL)
            return;
        inorderTraversalCore(root->left, result);
        result.push_back(root->val);
        inorderTraversalCore(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorderTraversalCore(root, result);
        return result;
    }

    vector<int> inorderTraversal_iteratively(TreeNode *root)
    {
        vector<int> result;        
        if(root == NULL)
            return result;
        TreeNode *p = root;
        stack<TreeNode *> s;
        while(p || !s.empty())
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
            if(!s.empty())
            {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};