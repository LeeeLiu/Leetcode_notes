

// 遍历数组，固定cur位置，
// 其它两个位置，使用前，后，指针。
// 注意去重。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 先排序。方便后面去重。
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;        
        for(int cur=0; cur<nums.size(); cur++)
        {
            int target = 0 - nums[cur];
            int front = cur + 1;
            int back = nums.size() -1;
            while(front<back)
            {
                int sum = nums[front]+nums[back];
                if(sum==target)
                {
                    // 找到一个解
                    res.push_back({nums[cur],nums[front],nums[back]});
                
                    // front和back位置去重
                    while(front < back && nums[front]==nums[front+1])   front++;
                    while(front < back && nums[back]==nums[back-1])   back--;
                
                    front++;
                    back--;
                }
                if(sum>target)  back --;
                                
                if(sum<target)  front ++;
                
            }
            // cur位置去重
            while(cur<nums.size()-1 && nums[cur]==nums[cur+1])   cur++;
        }
        
        return res;
    }
};