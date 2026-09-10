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
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1 + helper(root->left) + helper(root->right);
    }           
    void helper2(TreeNode* root,int &sum){
        if(root==NULL){
            return ;
        }
        sum+=root->val;
        if(root->left){
            helper2(root->left,sum);
        }
        if(root->right){
            helper2(root->right,sum);
        }
    }
    int ans = 0;
    void worker(TreeNode* root){
        if(root==NULL){
            return ;
        }
        int a = 0;
        int x = helper(root);
        helper2(root,a);
        if((a/x) == root->val){
            ans++;
        }
        if(root->left){
            worker(root->left);
        }

        if(root->right){
            worker(root->right);
        }
    }
    int averageOfSubtree(TreeNode* root){
        worker(root);

        return ans;
    }
};