
#include <iostream>
#include <vector>
#include <queue>
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
    
    //solution one: bfs
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> result;
        if(root == nullptr)
        {
            return result;
        }
        
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if(tmp->left != nullptr)
                {
                    q.push(tmp->left);
                }
                if(tmp->right != nullptr)
                {
                    q.push(tmp->right);
                }
            }
            result.push_back(v);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    
    void helper(TreeNode *root, vector<vector<int>>& result, int level)
    {
        if(root == nullptr)
            return;
        if(level == result.size())
        {
            vector<int> v;
            result.push_back(v);
        }
        result[level].push_back(root->val);
        
        helper(root->left, result, level + 1);
        helper(root->right, result, level + 1);
        return;
    }
    
    //solution two: dfs, recursive
    vector<vector<int>> levelOrderBottom_2(TreeNode *root)
    {
        vector<vector<int>> result;
        helper(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }
    
    
    //solution three: dfs, iterative
    vector<vector<int>> levelOrderBottom_3(TreeNode *root)
    {
        vector<vector<int>> result;
        if(root == NULL)
        {
            return result;
        }
        stack<pair<TreeNode *, int>> s;
        s.push(pair<TreeNode *, int>(root, 0));
        while(!s.empty())
        {
            pair<TreeNode *, int> p = s.top();
            s.pop();
            TreeNode *node = p.first;
            int level = p.second;
            if(node == nullptr)
                continue;
            if(level == result.size())
            {
                vector<int> v;
                result.push_back(v);
            }
            result[level].push_back(node->val);
            s.push(pair<TreeNode *, int>(node->right, level+1));
            s.push(pair<TreeNode *, int>(node->left, level+1));
        }
        reverse(result.begin(), result.end());
        return result;
    }
};