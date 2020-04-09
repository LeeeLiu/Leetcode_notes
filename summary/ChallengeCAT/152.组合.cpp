描述
给定两个整数 n 和 k. 返回从 1, 2, ... , n 中选出 k 个数的所有可能的组合.
你可以以任意顺序返回所有的组合, 但是一个组合内的所有数字需要是升序排列的.

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>one_combine;
        vector<vector<int>>res;
        int v = 1;
        find(n, k, v, one_combine, res);
        return res;
        // write your code here
    }
    void find(int n, int k, int v, vector<int>& one_combine, vector<vector<int>>& res)
    {
        if(one_combine.size()==k)
        {
            res.push_back(one_combine);
            return;
        }
        for(int i=v; i<=n; i++)
        {
            one_combine.push_back(i);
            find(n, k, i+1, one_combine, res);
            one_combine.pop_back();
        }
    }
};