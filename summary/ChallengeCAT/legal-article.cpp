class Solution {
public:
    /**
     * @param s: the article
     * @return: the number of letters that are illegal
     */
//      给定一篇由大写字母、小写字母、逗号、句号组成的文章，求使文章不合法的字母数。
// 文章不合法有2种情况：
// 1.句子的第一个字母用了小写。
// 2.不是单词的首字母用了大写。

// 一个句子当且仅当句号时结束。
    int count(string &s)
    {
        int res=0;
        bool sentence_start = true;
        for(int i=0; i<s.size(); i++)
        {
            // 1.句子的第一个字母，用了小写。
            if(sentence_start==true && s[i]>='a' && s[i]<='z')
                res++;
                
            if(s[i]=='.')
                sentence_start=true;
            if( (s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z') )
                sentence_start=false;
            
            // 2.不是单词首的字母，用了大写。
            if(i>0 && (s[i-1]!=' ' && s[i-1]!='.' && s[i-1]!=',') )
            {
                if(s[i]>='A' && s[i]<='Z')
                    res++;
            }
        }
        return res;
    }
};
