

### 905. Sort Array By Parity
>描述：把数组中所有偶数元素排前面，奇数元素排后面。
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

1. 维护一个保存结果的数组r --> O(n) space
    遍历数组A --> O(n) time 偶数元素插在r前面，奇数元素插在r后面。
    ```
    class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& A) {        
            vector<int>r;                      //新建vector对象r(结果)
            for(int i=0; i<A.size(); i++){
                if (A[i]%2 == 0){
                    r.insert(r.begin(),A[i]); //偶数往前插
                }
                else {
                    r.push_back(A[i]); //奇数往后插
                }
            }
            return r;
        }
    };
    ```
2. 直接在原数组上插入和删除：O(1) space，O(n) time
    ```
    int i;
            for(i=0;i<A.size();i++){
                if(A[i]%2 == 0){
                    A.insert(A.begin(),A[i]); //把A中偶数元素往A前面插入
                    A.erase(A.begin()+i+1);   //删除原来位置上的偶数元素
                }
            }
        return A;
    ```
3. 直接在原数组上做交换。（最佳）
   - 设置计数器count，记录当前遍历了几个偶数。把当前遍历到的A[i]与A[count]交换。
   - O(1) space，O(n) time
    ```
    class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& A) {
            int i,count=0;
            for(i=0;i<A.size();i++)
                if(A[i]%2==0)
                {
                    swap(A[i],A[count]);    //交换
                    count++;
                }
            return A;
        }
    };
    ```
### 922. Sort Array By Parity II
>描述：调整数组A顺序，使得奇数位元素是奇数，偶数位是偶数。
 - 维护两个大小为n/2的数组odd even。遍历数组A，将奇数存在odd，偶数存在even。
 - 遍历数组A，将A所有元素重新赋值。每次取尾部元素even或odd.back()，再弹出尾部元素even或odd.pop_back()。
 - 时空复杂度：O(n) space, O(2n) time.
    ```
    class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& A) {
            vector<int> odd, even;
            int i;
            for ( i = 0; i < A.size(); ++i) {
                if (A.at(i) % 2 == 0) {
                    even.push_back(A.at(i));
                } else {
                    odd.push_back(A.at(i));
                }
            }
            
            for ( i = 0; i < A.size(); ++i) {
                if (i % 2 == 0) {
                    A[i] = even.back(); //取尾部元素
                    even.pop_back();    //删除尾部元素
                } else {
                    A[i] = odd.back();
                    odd.pop_back();
                }
            }
            return A;
        }
    };
    ```