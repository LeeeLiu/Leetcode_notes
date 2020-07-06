

// 63. 不同路径 II
// 这道题和‘62. 不同路径’  做法差不多，只是多了障碍物而已。
// 网格中的障碍物和空位置分别用 1 和 0 来表示。

// 描述[回顾]：
// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



class Solution {
public:
    // 障碍物是1，空位置是0 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        int i, j;
        for(i=0; i<m && obstacleGrid[i][0]==0; i++)
                dp[i][0] = 1;
        for(j=0; j<n && obstacleGrid[0][j]==0; j++)            
                dp[0][j] = 1;
        
        for(i=1; i<m; i++){
            for(j=1; j<n; j++){
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                // else if(obstacleGrid[i][j]==1)                    
                //     dp[i][j] = 0;
            }
        }
        return dp[m-1][n-1];
    }
};