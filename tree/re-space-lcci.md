
### 面试题 17.13. 恢复空格
1. 描述：你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。
2. 两种思路
    - 暴力DP：借鉴方法[单词拆分](../DP/139.word-break.md)👉超时
    - 字典树
    https://leetcode-cn.com/problems/re-space-lcci/solution/hui-fu-kong-ge-by-leetcode-solution/
3. 实现
    - 暴力DP
    ```
    class Solution {
    public:
        int respace(vector<string>& wordDict, string s) {        
            //num_unidentified_char[i]表示s前i个字符里未识别的字符数。
            vector<int>num_unidentified_char(s.size()+1, 0);
            int i,j,k;
            for(j=1; j<=s.size(); j++)   // 遍历 隔断位置j
            {
                // 假设当前字符作为单词不在字典中
                num_unidentified_char[j] = num_unidentified_char[j-1]+1;
                for(i=0; i<j; i++)  // 遍历j之前的位置i, 在字典里查找有无j-i长度的词
                {                
                    for(auto w:wordDict)
                    {                            
                        if(j-i==w.size())
                        {
                            for(k=0; k<w.size() && w[k]==s[i+k]; k++);
                            if(k==w.size()){
                                num_unidentified_char[j] = min(num_unidentified_char[j], num_unidentified_char[i]);
                                break;
                            }
                        }
                        
                    }
                }
            }
            return num_unidentified_char[s.size()];

        }
    };
    ```

    - 字典树
    ```

    ```