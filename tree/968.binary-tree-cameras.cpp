

// 968. 监控二叉树
    // 给定一个二叉树，要在一些节点上安装摄像头。
    // 每个节点的监控范围是：
        // 自己、父节点、子节点。
    // 问：要想监控到所有节点，一共(最少)需要多少个摄像头？

// 思路
    // 定义三个状态码(详见宏定义)
    // 深搜(类似前序遍历)
    // 根据左右子节点状态，来确定 当前节点 状态。

# define UNCOVERED_without_CAMERA      0  // 未被监控（当然，自己没有安装相机）
# define COVERED_without_CAMERA        1  // 可被监控（自己没有安装相机）
# define With_CAMERA                   2  // 自己 需要/已经 安装 相机
# define NOT_USED_CODE                -1  // 错误状态，未使用

class Solution {
public:
    int res=0;  // 要返回的结果

    int dfs(TreeNode* root){
        
        // 走到NULL节点，视作已覆盖
        if(!root)
            return COVERED_without_CAMERA;
        
        int left_status = dfs(root->left);
        int right_status = dfs(root->right);
        
        // 根据左右子节点状态，来确定 当前节点 状态
        
        // 左右子节点都被监控到（子节点的子节点装相机了），
        // 所以，自己就没有被监控到了（自己没有相机嘛）
        // 其实，是希望 父节点来装相机hh
        if(left_status==COVERED_without_CAMERA && right_status==COVERED_without_CAMERA)
        {
            return UNCOVERED_without_CAMERA;
        }            
        else if(left_status==UNCOVERED_without_CAMERA || right_status==UNCOVERED_without_CAMERA)
        {
            res ++;
            return With_CAMERA;
        }
        else if(left_status==With_CAMERA || right_status==With_CAMERA){
            return COVERED_without_CAMERA;
        }            
        else{
            return NOT_USED_CODE;
        }
    }
    int minCameraCover(TreeNode* root) {
        // 根节点是NULL，直接返回0个相机
        if(!root)
            return res;

        int root_status = dfs(root);
        if(root_status==UNCOVERED_without_CAMERA){
            res ++;
        }
        return res;
    }
};