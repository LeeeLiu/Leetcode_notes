
// 941. 有效的山脉数组

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)
            return false;
        int i, j;

        // 递增
        for(i=1; i<A.size() && A[i-1]<A[i] ;i++);
        
        // 单调递增或者单调递减 都不行
        if( i==1 || i==A.size())
            return false;

        // 递减
        for(j=i; j<A.size() && A[j-1]>A[j] ; j++);

        if(j==A.size())
            return true;
        else
            return false;

    }
};