


class Solution {
public:
    int findFirstBadVersion(int n) {
        int left=1, right=n;
        // int mid;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            // 由于left+right会超过INT_MAX
            // mid=(left+right)/2会“Time Limit Exceeded”
            if(SVNRepo::isBadVersion(mid))
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
        // write your code here
    }
};