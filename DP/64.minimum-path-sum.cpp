

/*
    64. 最小路径和
    给定一个包含非负整数的 m x n 网格，
    找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
    说明：每次只能向下或者向右移动一步。
*/

/*
    思路：动态规划
    定义一个和grid长宽一样的数组dp
    初始化+转移方程：
        左上角元素 dp[0][0] = grid[0][0]
        第一行、第一列，只能由左边、上边的状态转移而来。即
            dp[0][j] = dp[0][j-1] +grid[0][j];
            dp[i][0] = dp[i-1][0] +grid[i][0];
        其它情况：dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
    最后，返回 dp[n-1][m-1]，即为答案。
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dp(n,vector(m, 0));
        int i,j;

        dp[0][0] = grid[0][0];
        for(i=1; i<n; i++)
            dp[i][0] = dp[i-1][0] +grid[i][0];

        for(j=1; j<m; j++)
            dp[0][j] = dp[0][j-1] +grid[0][j];

        for(i=1; i<n; i++){
            for(j=1; j<m; j++){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }

        return dp[n-1][m-1];
    }
};