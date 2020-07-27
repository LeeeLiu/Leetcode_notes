
/*
    392. 判断子序列
    给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

    初始化两个指针 i 和 j，分别指向 s 和 t 的初始位置。
    每次贪心地匹配。
    匹配成功则 i 和 j 同时右移，匹配 s 的下一个位置，
    匹配失败则 j 右移，i 不变，尝试用 t 的下一个字符匹配 s。

    最终如果 i 移动到 s 的末尾，就说明 s 是 t 的子序列。

    时间复杂度：O(n+m)，其中 n 为 s 的长度，m 为 t 的长度。

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;                
            }
            j++;
        }
        if(i==s.size())
            return true;
        else
            return false;

    }
};