
// 描述：
// 输入两个整数序列，
// 第一个序列表示栈的压入顺序，
// 请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。

// 思路：
// 给定一个压入序列 pushedpushedpushed 和弹出序列 poppedpoppedpopped ，
// 则压入 / 弹出操作的操作顺序（即排列）是 唯一确定 的。
// 如果这种操作存在，则返回true。否则false。


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> cache;
        int i=0;
        for(auto value: pushed)
        {
            cache.push(value);
            while(!cache.empty() && popped[i]==cache.top())
            {
                cache.pop();
                i++;
            }
        }
        if(cache.empty())
            return true;
        else
            return false;
    }
};