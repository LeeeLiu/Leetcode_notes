

### 1139. Largest 1-Bordered Square
>描述：有一个元素为0或1的矩阵。求矩阵中元素均为1的最大正方形中的元素个数。
难度Medium
Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
[题解参考](https://www.geeksforgeeks.org/given-matrix-o-x-find-largest-subsquare-surrounded-x/)
```
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int i, j, m = grid.size(), n = grid[0].size();
        int small, max, horizon[m][n], vertical[m][n];        
        //第一个双重循环：初始化horizon和vertical矩阵，
        //分别存储水平、垂直方向上，连续的“1”的个数。
        for(i=0; i<m; i++)
        {            
            for(j=0; j<n ;j++)
            {
                if(grid[i][j]==0)
                    horizon[i][j] = vertical[i][j] = 0;   
                else
                {
                    horizon[i][j] = (j!=0)?(horizon[i][j-1]+1):1 ;       
                    vertical[i][j] = (i!=0)?(vertical[i-1][j]+1):1 ;
                }                
            }            
        }
        //第二个双重循环：对于矩阵grid，右下角-->左上角遍历。        
        max = 0;
        for(i=m-1; i>=0; i--)    
        {
            for(j=n-1; j>=0; j--)
            {   //保存horizon、vertical相同位置[i,j]上的较小值（构成正方形条件1）为small。
                small = min(horizon[i][j], vertical[i][j]);
                while(small>max)    //寻找更大的正方形
                {
                    if(horizon[i-small+1][j]>=small && vertical[i][j-small+1]>=small)
                        max = small;    //满足构成正方形（边长是max）条件2，跳出while循环。
                    else
                        small--;
                }
            }
        }
        
        return max*max;
    }
};
```
