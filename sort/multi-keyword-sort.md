
### 846. 多关键字排序
>来自lintcode
1. 描述：
给定 n 个学生的学号id(从 1 到 n 编号)以及他们的考试成绩score，表示为(学号，考试成绩)，请将这些学生按考试成绩降序排序，若考试成绩相同，则按学号升序排序。
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