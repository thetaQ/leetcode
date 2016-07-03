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
    TreeNode *helper(vector<int>& preorder, int preorder_start, int preorder_end, 
                     vector<int>& inorder, int inorder_start, int inorder_end)
    {
        if(preorder_end < preorder_start || preorder_end-preorder_start != inorder_end-inorder_start)
        {
            return NULL;
        }
        //get first number from preorder
        int root_val = preorder[preorder_start];
        TreeNode *root = new TreeNode(root_val);
        int index = -1;
        for(int i = inorder_start; i <= inorder_end; i ++)
        {
            if(inorder[i] == root_val)
            {
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            //invalid input
            return NULL;
        }

        int left_length = index - inorder_start;
        root->left = helper(preorder, preorder_start+1, preorder_start+left_length, inorder, inorder_start, index-1);
        root->right = helper(preorder, preorder_start+left_length+1, preorder_end, inorder, index+1, inorder_end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};