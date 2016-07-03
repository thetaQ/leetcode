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
    TreeNode *helper(vector<int>& inorder, int inorder_start, int inorder_end,
                    vector<int>&postorder, int postorder_start, int postorder_end)
    {
        if(inorder_end < inorder_start || inorder_end-inorder_start != postorder_end-postorder_start)
        {
            return NULL;
        }

        int root_val = postorder[postorder_end];
        TreeNode *root = new TreeNode(root_val);

        int index = -1;
        for(int i = inorder_start; i <= inorder_end; i++)
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
        root->left = helper(inorder, inorder_start, index-1, postorder, postorder_start, postorder_start+left_length-1);
        root->right = helper(inorder, index+1, inorder_end, postorder, postorder_start+left_length, postorder_end-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};