
### 347. 前 K 个高频元素
1. 描述：
    给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
    数组中存在频率相同的元素.
2. 实现
    - 桶排序
    ```
    class Solution {
    public:    
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int>freq0;
            for(auto n:nums)
                freq0[n]++;
            
            // nums中存在频率相同的元素
            vector<vector<int>>freq(nums.size()+1);
            for(auto f:freq0)
                freq[f.second].push_back(f.first);
            
            vector<int>res;
            for(int times = nums.size(); times>=0; times--)
            {        
                // if(res.size()==k)
                //         break;            
                for(auto num: freq[times])
                {
                    if(res.size()==k)
                        return res;
                    res.push_back(num);
                }
            }
            return res;
        }
    };
    ```

    - 堆1。用所有数据建堆。
    ```
    class Solution {
    public:
    struct compare {
        bool operator()(const pair<int,int>&a, const pair<int,int>&b) {
            return a.second < b.second;
        }
        };
        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int,int>M;
            for(auto n:nums)
                M[n]++;
            vector<pair<int,int>>p;
            for(auto m: M)
                p.push_back(make_pair(m.first, m.second));

            priority_queue<pair<int,int>, vector<pair<int,int>>, compare> Q(p.begin(),p.end());        
            vector<int>res;
            for(int i=0; i<k; i++)
            {
                res.push_back(Q.top().first);
                Q.pop();
            }
            return res;
        }
    };
    ```

    - 堆2(同1)。维护一个size=K的最小堆(greater)。前K大用最小堆，前K小用最大堆。
    ```
    class Solution {
    public:
    struct compare {
        bool operator()(const pair<int,int>&a, const pair<int,int>&b) {
            return a.second > b.second;    // greater最小堆。维护一个size=K的最小堆。
        }
        };
        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int,int>M;
            for(auto n:nums)    
                M[n]++;                
             
             // greater最小堆。维护一个size=K的最小堆。
             // 前K大用最小堆，前K小用最大堆。
            priority_queue<pair<int,int>, vector<pair<int,int>>, compare> Q;
            for(auto m:M)
            {
                Q.push(make_pair(m.first, m.second));
                if(Q.size()>k)    Q.pop();
            }
            /*
            for(auto m:M)
            {            
                if(Q.size() >= k)
                {
                    if(m.second < Q.top().second)
                        continue;
                    else
                        {
                            Q.pop();
                            Q.push(make_pair(m.first, m.second));
                        }
                }
                else
                    Q.push(make_pair(m.first, m.second));
            }
            */

            vector<int>res;
            while(!Q.empty())
            {
                res.push_back(Q.top().first);
                Q.pop();
            }
            return res;
        }
    };
    ```