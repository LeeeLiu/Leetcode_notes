class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>Q;
        TreeNode* cur;
        Q.push(root);
        int cur_level_size, i;
        double avg_per_level;
        vector<double>res;
        while(!Q.empty()){
            avg_per_level = 0;     
            cur_level_size = Q.size();       
            for(i=0; i<cur_level_size; i++){
                cur = Q.front();
                Q.pop();
             
                avg_per_level += cur->val;
                if(cur->left)    Q.push(cur->left);
                if(cur->right)    Q.push(cur->right);                                   
            }
            avg_per_level /= cur_level_size;
            res.push_back(avg_per_level);
        }
        return res;
    }
};