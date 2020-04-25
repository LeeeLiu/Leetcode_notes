
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left=0, right=n-1,mid;
        if(n==0)    return -1;
        // 如果是递增数组(没有旋转)
        if(nums[0]<=nums[n-1])  return nums[0];
        // 如果递增数组旋转
        while(left<right)
        {
            mid = left +(right-left)/2;
            if(nums[mid]>=nums[0])
                left = mid +1;
            if(nums[mid]<nums[0])
                right = mid;
        }
        return nums[left];
        // write your code here
    }
};