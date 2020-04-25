

// 1753. 写作业
// 描述
// n个人，他们每个人需要独立做m份作业。
// 第i份作业需要花费cost[i]的时间。由于每个人的空闲时间不同，第i个人有val[i]的时间，这代表他做作业的总时间不会超过val[i]。每个人都按照顺序，从1号作业开始，然后做2号，3号...... 现在，你需要计算出他们最多花了多少的时间。

// 样例 1:
// 给定`cost=[1,2,3,5]`，`val=[6,10,4]`，返回`15`。
// 输入:
// [1,2,3,5]
// [6,10,4]
// 输出：15

// 解释:
// 第一个人可以完成1号作业，2号作业，3号作业，1+2+3<=6。
// 第二个人可以完成1号作业，2号作业，3号作业，无法完成4号作业，1+2+3<=10，1+2+3+5>10。
// 第三个人可以完成1号作业，2号作业，无法完成3号作业，1+2<=4，1+2+3>4。
// 1+2+3+1+2+3+1+2=15，返回15。


class Solution {
public:
    long long doingHomework(vector<int> &cost, vector<int> &val) {
        long long sum = 0;
        long long res = 0;
        int i=0, j=0;
        sort(val.begin(), val.end());
        
        while(j<val.size())
        {
            if( sum + cost[i] <= val[j])
            {
                sum += cost[i];
                i++;
                continue;
            }                
            if(sum + cost[i] > val[j])
            {
                res += sum;
                j++;
            }            
        }        
        return res;
        // Write your code here.
    }
};