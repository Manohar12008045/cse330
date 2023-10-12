class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> ans;
        ans.push_back(root);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();q.pop();
            if(temp==NULL)continue;
            q.push(temp->left);
            ans.push_back(temp->left);
            q.push(temp->right);
            ans.push_back(temp->right);
        }
        int i=0;int lock=0;
        while(i<ans.size()){
            if(ans[i]==NULL)lock=1;
            else if(lock==1)return false;
            i++;
        }
        return true;
    }
};
