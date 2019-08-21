
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

>方法：维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。
（1）如果当前遍历到的字符从未出现过，那么直接扩大右边界；
（2）如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；
（3）重复（1）（2），直到左边索引无法再移动；
（4）维护结果res，每次用出现过的窗口大小来更新结果res，最后返回res获取结果。
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, res=0,win_start=0; 
        //win_start记录滑动窗口左侧边界，i是当前窗口右侧边界
        map<char,int>pre_pos; //记录字母上一次出现的位置
        for(i=0;i<s.size();i++)
        {
            if(pre_pos[s[i]]!=0 )
                win_start=max(win_start,pre_pos[s[i]]);
            
            pre_pos[s[i]]=i+1;
            res=max(res,i-win_start+1);
        }        
        return res;
    }
};
```