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
int grd=-1;
TreeNode *ans=NULL;

int dfs(TreeNode* root,int d){
    if(root==NULL) return d-1;

    int ld=dfs(root->left,d+1);
    int rd=dfs(root->right,d+1);
    int a=min(ld,rd);
    if(a>=grd){
        grd=a;
        ans=root;
    }
    return max(ld,rd);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};