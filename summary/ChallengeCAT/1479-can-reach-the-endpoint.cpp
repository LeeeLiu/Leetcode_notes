

// 大小为 m*n 的map
// 1 代表空地，0 代表障碍物，9代表终点。
// 只能↓或者→走
// 请问如果你从 (0, 0) 开始能否到达终点？

// 思路：BFS。

class Solution {
public:
    /**
     * @param matrix: the matrix
     * @return: can you reach the endpoint
     */
    bool reachEndpoint(vector<vector<int>> &matrix) {
        int m = matrix.size(), n=matrix[0].size();
        queue<pair<int, int>> Q;
        
        int i=0, j=0;
        Q.push(make_pair(0,0));
        pair<int, int> cur;
        while(!Q.empty())
        {
            cur = Q.front();
            Q.pop();
            i = cur.first;
            j = cur.second;
            if(matrix[i][j]==9)     return true;
            
            if(i+1<m && (matrix[i+1][j]==1 || matrix[i+1][j]==9))
                Q.push(make_pair(i+1,j));
            
            if(j+1<n && (matrix[i][j+1]==1 || matrix[i][j+1]==9) )
                Q.push(make_pair(i,j+1));
            
        }
        
        return false;
        // Write your code here
    }
};