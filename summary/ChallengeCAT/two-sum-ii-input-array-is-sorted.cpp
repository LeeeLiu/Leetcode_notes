

// 方法1， 哈希表，时间复杂度O（N），方法同1.Two-sum
// 方法2，二分法，O（logN）。方法借鉴search-insert-position。

class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<=right)
        {
            if(nums[left]+nums[right]==target)
                return vector<int>{left+1, right+1};
            else if(nums[left]+nums[right]<target)
                left++;
            else
                right--;
        }
        
        return vector<int>{left+1, right+1};
        // write your code here
    }
};