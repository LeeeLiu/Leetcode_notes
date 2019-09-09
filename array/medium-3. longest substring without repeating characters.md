
### 3. Longest Substring Without Repeating Characters
>描述：难度Medium
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
(Note that the answer must be a substring, "pwke" is a subsequence and not a substring.)

1. 方法：维护一个滑动窗口，向右滑动--> O(n) time。窗口内都是不重复的字符，尽可能扩大窗口的大小。
（1）如果当前遍历到的字符`出现过`，则缩小窗口（这个字符的pre_pos在窗口内，将左边界win_start替换为pre_pos）或者窗口左边界不变（这个字符的pre_pos在窗口外部左侧）。
（2）记录字符串s每个字符的位置pre_pos。（相同字符的位置取最新的索引值）--> O(n) space。
（3）维护结果res，每次用当前窗口大小来更新结果res，最后返回结果。
2. 实现：O(n) time，O(n) space。
    ```
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int i, res=0, win_start=0; 
            //win_start记录滑动窗口左侧边界，i是当前窗口右侧边界
            map<char,int>pre_pos; //记录字母上一次出现的位置
            for(i=0;i<s.size();i++)
            {
                if(pre_pos[s[i]]!=0 )   // s[i]有出现过
                    win_start = max(win_start,pre_pos[s[i]]);  //更新窗口左边界win_start
                
                pre_pos[s[i]]=i+1;  // 记录位置
                res = max(res, i-win_start+1);  //计算当前窗口大小，更新res
            }        
            return res;
        }
    };
    ```