
### 面试题 16.11. 跳水板
1. 描述：
    - 使用两种类型的木板，建造跳水板。
    - 其中长度较短的木板长度为shorter，长度较长的木板长度为longer。
    - 你正好使用k块木板。
    - 编写一个方法，生成跳水板所有可能的长度。
    - 返回的长度需要从小到大排列。
2. 实现
    ```
    class Solution {
    public:
        vector<int> divingBoard(int shorter, int longer, int k) {         
            // 三种情况：k==0、shorter==longer、shorter < longer
            if(k==0)
                return vector<int>{};
            if(shorter==longer)
                return vector<int>{shorter*k};
            
            int num_shorter;  
            vector<int> res(k+1);  // 这样赋值，res里的值就是递增的。
            for(num_shorter=k; num_shorter>=0; num_shorter--){
                res[k-num_shorter] = (num_shorter*shorter + (k-num_shorter)*longer);                  
            }
            
            return res;
        }
    };
    ```