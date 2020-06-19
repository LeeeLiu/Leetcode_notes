

// 方法1：优先队列/堆（通过）
[题解](https://www.jiuzhang.com/problem/best-time-to-buy-and-sell-stock-v/)

// 方法2：超时。仅通过80％测试数据。
class Solution {
public:    
    int getAns(vector<int> &A) {        
        vector<int> min_list;
        int res = 0;
        for(auto a: A)
        {
            if(min_list.size()>0 && a > min_list[0])
            {
                res += (a-min_list[0]);
                min_list.erase( min_list.begin() );
                
                min_list.push_back(a);
            }
            min_list.push_back(a);
            sort(min_list.begin(), min_list.end());
        }
        return res;
    }
};

// 方法3：利用快排（通过）
// 使用了第K小元素的方法。参考了力扣215题
class Solution {
public:
    int QuickSelect(vector<int> &A, int l, int r)
    {
        // if(l>r)
        //     return;    
        int pos = rand()%(r-l+1) + l;   // 生成【l,r】之间随机整数
        int pivot = A[pos];
        //始终将第一个元素作为pivot, 若不是, 则与之交换
        if (pos != l) {
            swap(A[l], A[pos]);
        } 
        
        int i=l, j=r;
        
        while(i<j)
        {
            while(A[j]<=pivot && i<j) j--;
            while(A[i]>=pivot && i<j) i++;
            if(i<j)
                swap(A[i], A[j]);
        }
        
        swap(A[i], A[l]); //pivot归位
        // quick_sort(A, l, i-1);
        // quick_sort(A, i+1, r);
        
        return i;
    }
        
    int findKthSmallest(vector<int> &nums, int k) {
        srand((unsigned)time(NULL));
        int index, left=0, right=nums.size()-1;
        int n = nums.size();
        while(left<right)
        {
            index = QuickSelect(nums, left, right);
            if(index==n-k)
                break;
            else if(index > n-k)    right = index-1;            
            else    left = index+1;
        
        }
        return nums[n-k];
        // write your code here
    }

    int getAns(vector<int> &A) {
        vector<int> min_list;
        int res = 0;
        for(auto a: A)
        {
            if(min_list.size()>0 && a > findKthSmallest(min_list,1))
            {
                res += (a - findKthSmallest(min_list,1));
                min_list.pop_back();
                
                min_list.push_back(a);
            }
            min_list.push_back(a);
        }
        return res;
    }
};