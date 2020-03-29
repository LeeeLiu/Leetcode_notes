
### search-insert-position
>来自lintcode 60. 搜索插入位置
1. 描述：给定一个排序数组和一个目标值，如果在数组中找到目标值则返回索引。如果没有，返回到它将会被按顺序插入的位置。（数组中无重复元素）
2. 二分查找。时间复杂度为O(log(n))
3. 实现
```
class Solution {
public:
    int searchInsert(vector<int> &A, int target) {
        if(!A.empty() )
        {
            int left=0, right=A.size()-1, mid;
            while(left<=right)
            {
                mid = (left+right)/2;
                if(A[mid]==target)
                    return mid;
                else if(A[mid]>target)
                    right = mid-1;
                else
                    left = mid+1;
            }
            // 如果没找到target，返回插入位置
            if(A[mid]<target)
                return mid+1;
            else
                return mid;
        }
        return 0;
        // write your code here
    }
};
```
