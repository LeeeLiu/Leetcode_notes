/*
    216. 组合总和 III
    找出所有相加之和为 n 的 k 个数的组合。
    组合中只允许含有 1 - 9 的正整数
    每种组合中不存在重复的数字。
*/

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& path, int k, int target, int start){
        if(path.size()==k && target==0){
            res.push_back(path);
            return;
        }
        for(int i=start; i<10 && target>0; i++){
            path.push_back(i);
            dfs(res, path, k, target-i, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>path;
        dfs(res, path, k, n, 1);
        return res;
    }
};