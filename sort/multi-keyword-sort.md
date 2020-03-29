
### 846. 多关键字排序
>来自lintcode
1. 描述：
给定 n 个学生的学号id(从 1 到 n 编号)以及他们的考试成绩score(范围0~100整数)，表示为(学号，考试成绩)，请将这些学生按考试成绩降序排序，若考试成绩相同，则按学号升序排序。
2. 根据桶排序的思路，有主位优先和次位优先两个策略。
	- 方法1，主位优先：先以成绩score作为键值建桶（每个桶里装多个id）；再对每个桶里的id排序；合并结果。
    ```
    class Solution {
    public:    
        vector<vector<int>> multiSort(vector<vector<int>> &array) {
            if(!array.empty())
            {
                map<int, vector<int>>bucket;	//以成绩score作为键值建桶，每个桶里装多个学号id。score会重复，但是id不会重复。
                for(auto a:array)
                    bucket[a[1]].push_back(a[0]);
                
                array.clear();
                int score;	//分数范围已知【0，100】，这里就很方便做降序了。
                for(score=100; score>=0; score--)
                {
                    if(!bucket[score].empty())
                    {
                        sort(bucket[score].begin(), bucket[score].end());	//每个桶里的id排序。
                        for(auto id: bucket[score])
                            array.push_back({id, score});
                    }
                        
                }
            }
            
            return array;
            // Write your code here
        }
    };
    ```
    - 方法2，次位优先。1）先以id为键值建桶；按照id递增顺序合并结果；2）以score为键值建桶；按照score递减顺序合并结果。
    ```
    class Solution {
    public:
        vector<vector<int>> multiSort(vector<vector<int>> &array) {
            if(!array.empty())
            {
                //以id为键值，建桶
                map<int,int>bucket;
                for(auto a:array)
                    bucket[a[0]] = a[1];
                //按照id递增顺序，合并结果
                int id_num = array.size();
                array.clear();
                for(int id=1; id<=id_num; id++)
                    array.push_back({id, bucket[id]});
                //以score为键值，建桶
                map<int, vector<int>>bucket_one2more;
                for(auto a:array)
                    bucket_one2more[a[1]].push_back(a[0]);
                //合并结果
                array.clear();
                for(int score=100; score>=0; score--)
                    if(!bucket_one2more[score].empty())
                    for(auto id:bucket_one2more[score])
                        array.push_back({id, score});
            }
            return array;
            // Write your code here
        }
    };
    ```
    - 方法3，[偷懒的做法](#3)
    ```
    class Solution {
    public:
        bool static cmp(vector<int>&a ,vector<int>&b)
        {
            if(a[1]>b[1])   return true;            
            if(a[1]==b[1] && a[0]<b[0])   return true;            
            return false;
        }
        vector<vector<int>> multiSort(vector<vector<int>> &array) {
            sort(array.begin(),array.end(), cmp);
            return array;
            // Write your code here
        }
    };
    ```
3. <p id="3">对于方法3的解释：方法1，2的前提是，id和score取值范围都已知。如果未知呢？</p>
- 使用内置函数，结构体排序
- 有结构体node。先按照w的值升序排序；
- 如果w相等，再按照v的值升序排序。
    ```
    struct node
    {
        int u, v, w;
    };
    ```
    ```
    bool cmp(node a, node b)
    {
        if(a.w==b.w)
            return a.v<b.v;
        else
            return a.w<b.w;
    }
    ```
    ```
    vector<node> &array;
    sort(array.begin(), array.end(), cmp);
    ```