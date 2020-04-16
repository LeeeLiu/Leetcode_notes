

// 描述:
// 数轴上有 n 个区间. 现在需要在数轴上选取一些点, 使得任意一个区间内至少包含一个点.
// 返回最少选取的点的数目.
// 样例 1:
// 输入: [(1,5), (4,8), (10,12)] 
// 输出: 2
//   解释: 
//   选择两个点: 5, 10
//   第一个区间 [1, 5] 包含了 5
//   第二个区间 [4, 8] 包含了 5
//   第三个区间 [10, 12] 包含了 10

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:    
    bool static cmp(Interval &a, Interval &b)
    {
        if(a.start == b.start) 
            return a.end < b.end;
        else
            return a.start < b.start;
    }
    int getAns(vector<Interval> &a) {
        if(a.empty())
            return 0;
        
        sort(a.begin(), a.end(), cmp);
        int Interval_left = a[0].start;
        int Interval_right = a[0].end;

        int res=1;
        for(int i=1; i<a.size(); i++)
        {
            if(a[i].start <= Interval_right)
                Interval_right = min(Interval_right, a[i].end);
            else
                {
                    res ++;
                    Interval_left = a[i].start;
                    Interval_right = a[i].end;
                }
        }
        return res;
        // write your code here
    }
};