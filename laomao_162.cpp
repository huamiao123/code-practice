/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int num=0;
        int ret=0;
        int kthSmallest(TreeNode* root, int k) {
            dfs(root,k);
            return ret;
        }
        void dfs(TreeNode* root,int k)
        {
            if(root!=NULL)
            {
                if(ret==0)
                dfs(root->left,k);
                num++;
                if(num==k) ret=root->val;
                if(ret==0)
                dfs(root->right,k);
            }
        }
    };
    //https://leetcode.cn/problems/kth-smallest-element-in-a-bst/