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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vec;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            while(n--){
                TreeNode* x=q.front();
                q.pop();
                sum+=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                
            }
                vec.push_back(sum);

        }

        q.push(root);
        root->val=0;
        int i=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* y=q.front();
                q.pop();

                int sibsum= (y->left ?y->left->val : 0)+(y->right ? y->right->val : 0);
                if(y->left) {
                    y->left->val=vec[i]-sibsum;
                    q.push(y->left);
                }
                if(y->right) {
                    y->right->val=vec[i]-sibsum;
                    q.push(y->right);
                }
            }
            i++;
        }

        return root;
    }
};