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
    void postorderTraversalCore(TreeNode *root, vector<int>& result)
    {
        if(root == NULL)
            return;
        postorderTraversalCore(root->left, result);
        postorderTraversalCore(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        postorderTraversalCore(root, result);
        return result;
    }


    vector<int> postorderTraversal_iteratively(TreeNode* root)
    {
        vector<int> result;
        if(root == NULL)
            return result;
        TreeNode *p = root;
        stack<TreeNode *> s;
        TreeNode *last_visited = nullptr;
        while(p || !s.empty())
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
            
            p = s.top();            
            if(p->right == NULL || p->right == last_visited)
            {//右边已全部访问完毕
                s.pop();
                result.push_back(p->val);
                last_visited = p;
                p = NULL;
            }
            else
            {
                p = p->right;
            }
        }
        return result;
    }

};