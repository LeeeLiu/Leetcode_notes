

### 905. Sort Array By Parity
>描述：Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {        
        vector<int>r;
        for(int i=0; i<A.size(); i++){
            if (A[i]%2 == 0){
                r.insert(r.begin(),A[i]);
            }
            else {
                r.push_back(A[i]);
            }
        }
        return r;
    }
};
```
```
int i;
        for(i=0;i<A.size();i++){
            if(A[i]%2 == 0){
                A.insert(A.begin(),A[i]);
                A.erase(A.begin()+i+1);
            }                            
        }
    return A;
```
```
//目前 最佳
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i,count=0;
        for(i=0;i<A.size();i++)
            if(A[i]%2==0)
            {
                swap(A[i],A[count]);
                count++;
            }
        return A;
    }
};
```
### 922. Sort Array By Parity II
>Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
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
                A[i]=even.back();
                even.pop_back();
            } else {
                A[i]=odd.back();
                odd.pop_back();
            }
        }
        return A;
    }
};
```