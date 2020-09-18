

// 47. 全排列 II
    // 给定一个可包含 重复数字 的序列，返回所有 不重复 的全排列。

// 排列问题，一定用到 visit 变量。
    // 注意，本题中，visit标记的不是 数组里数字是否访问，而是数字下标是否访问。
    // 所以，除了 visit 变量，还需要一个 index 变量（与 组合问题里的start变量不同）
    // 每次 回溯，传参 index+1

//  相似问题一，`46. 全排列` 是  无重复 数字。
// 相似问题二， 40. 组合总和 II
    // 去重操作2步是类似的


class Solution {
public:
    void dfs(vector<int>& nums, 
             vector<vector<int>>& res,   vector<int>& path, 
             vector<int>& visit,         int index){

        if(index == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            // 易错：条件 i>0 必须放在第一个。
            // 2去除 解集 里 重复 组合
            if( i>0 &&  !visit[i-1] &&  nums[i]==nums[i-1] )
                continue;
            if(!visit[i]){ 
                visit[i] = 1;
                path.push_back(nums[i]);           
                dfs(nums, res, path, visit, index+1);
                path.pop_back();
                visit[i] = 0;
            }            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {                
        vector<int>path;
        vector<vector<int>>res;
        vector<int> visit(nums.size(), 0);
        
        // 1去除 解集 里 重复 组合
        sort(nums.begin(), nums.end());

        dfs(nums, res, path, visit, 0);
        return res;
    }
};