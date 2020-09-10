

// 40. 组合总和 II

// 本题(40)和题目(39)相比，区别是：
// candidates 中的每个数字，在每个组合中只能使用一次。
    // 那么，直接修改start变量：把题目(39)中 for循环里的 dfs(...,i) 改成 dfs(...,i+1)
    // 这样做有个问题：解集里有重复的组合。
        // 例如当 candidates=[2,2]，target=2 时，
        // 就会将列表 [2] 放入答案两次。
    // 所以，在题目(39)基础上，除了修改start变量之外，还要做去重操作。具体地：
        // 1.先对candidates数组排序
        // 2.遍历时候，遇到相同元素就跳过

class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int target, int start){
        if(target==0){        
            res.push_back(path);
            return;
        }
        for(int i=start; i<candidates.size() && target>0; i++){
            // 2去除 解集 里 重复 组合
            if (i > start && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            dfs(candidates, res, path, target-candidates[i], i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 1去除 解集 里 重复 组合
        sort(candidates.begin(), candidates.end());
        
        vector<int>path;
        vector<vector<int>>res;
        dfs(candidates, res, path, target, 0);
        
        return res;
    }
};