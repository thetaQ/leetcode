#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:

    //BFS
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                
                if(i == size-1)
                    result.push_back(tmp->val);
                if(tmp->left != NULL)
                {
                    q.push(tmp->left);
                }
                if(tmp->right != NULL)
                {
                    q.push(tmp->right);
                }
            }
        }
        return result;
    }

    //DFS
    void dfs(vector<int>& res, TreeNode *root, int level)
    {
        if(root == NULL)
            return;
        if(res.size() == level)
            res.push_back(root->val);
        dfs(res, root->right, level + 1);
        dfs(res, root->left, level + 1);
    }

    vector<int> rightSideView_2(TreeNode* root)
    {
        vector<int> res;
        dfs(res, root, 0);
        return res;
    }


};