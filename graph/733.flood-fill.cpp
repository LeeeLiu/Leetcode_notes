

// 733. 图像渲染
// 考点：回溯

// 题意：给定 newColor, 给图像 image 重新上色(油漆桶工具)。
    // 假设：初始位置[sr，sc] 颜色是 initposColor

// 上色规则：
    // 从 初始位置[sr，sc]出发，
    // 凡是 颜色为 initposColor 的位置，
    // 如果 相邻四个方向（上、下、左、右）颜色 都是 initposColor
    // 则，把 这些位置 都涂改为 newColor。    

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int initposColor, int newColor){
        if( sr>=0 && sr<image.size()  && sc>=0 && sc<image[0].size()    // 控制边界
            && image[sr][sc] == initposColor )
        {
                image[sr][sc] = newColor;

                dfs(image, sr-1, sc, initposColor, newColor);
                dfs(image, sr+1, sc, initposColor, newColor);
                dfs(image, sr, sc-1, initposColor, newColor);
                dfs(image, sr, sc+1, initposColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)
            return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};