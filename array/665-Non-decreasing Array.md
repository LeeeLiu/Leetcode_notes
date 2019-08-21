### 665. Non-decreasing Array
>描述：Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element. 
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n). 
Example 1:
Input: [4,2,3]
Output: True
Example 2:
Input: [4,2,1]
Output: False
Note: The n belongs to [1, 10,000].

1. 顺序检查凹变段和逆序检查凸变段。
如果满足，则asc和desc中的较小值必然不大于1。
时间开销O(n)，空间开销O(1)，缺点是双向检查，优点是便于理解。
```
class Solution {
    public boolean checkPossibility(int[] nums) {
        for(int i = 0, m = 0, n = nums.length - 1, asc = 0, desc = 0;i < nums.length;i++) {
            if(nums[m] <= nums[i]) m = i;
            else asc++;
            
            if(nums[n] >= nums[nums.length - 1 - i]) n = nums.length - 1 - i;
            else desc++;
            
            if(asc > 1 && desc > 1) return false;
        }
        
        return true;
    }
}
```
2. 检查nums[i-2],nums[i-1],nums[i]
```
bool checkPossibility(vector<int>& nums) {
        int cnt = 0;            //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];            //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];           //have to modify nums[i]
            }
        }
        return cnt<=1;
    } 
```
3. 当找到第一个反例（nums[i] > nums[i+1]）的时候，观察数组的其余部分是否按升序排序（没有nums [i]）OR（没有nums [i + 1]）。[来自](https://leetcode.com/problems/non-decreasing-array/discuss/106835/Very-easy-to-understand-C%2B%2B)
```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {  //这个比下面那个更快
        for (int i=0; i < nums.size()-1; i++){
            if (nums[i] > nums[i+1]){                
                int temp = nums[i];
                // "erase" nums[i], then check if nums is sorted without nums[i]
                nums[i] = nums[i+1];
                if (is_sorted(nums.begin(), nums.end()))
                    return true;                
                // "erase" nums[i+1], then check if nums is sorted without nums[i+1]
                nums[i+1] = nums[i] = temp;
                if (is_sorted(nums.begin(), nums.end()))
                    return true;                
                // nums is NOT sorted (without nums[i] XOR without nums[i+1])
                return false;
            }
        }
        return true;
    }
};
```
```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i,value,condition1,condition2;
        for(i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                value=nums[i];
                nums.erase(nums.begin()+i);
                condition1=is_sorted(nums.begin(),nums.end());
                nums.insert(nums.begin()+i,value);
                
                value=nums[i+1];
                nums.erase(nums.begin()+i+1);
                condition2=is_sorted(nums.begin(),nums.end());
                nums.insert(nums.begin()+i+1,value);
                
                if(condition1 || condition2)
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};
```