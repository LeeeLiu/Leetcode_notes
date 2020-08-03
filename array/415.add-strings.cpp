
/*
    415. 字符串相加
    给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
    注意：不能直接将输入的字符串转换为整数形式。
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        stack<int>sum;
        int single_pos_sum, carry=0;
        int i=num1.size()-1,j=num2.size()-1;
        int x1, x2;
        
        while(i>=0 || j>=0){
            x1 = (i>=0)? num1[i]-'0': 0;
            x2 = (j>=0)? num2[j]-'0': 0;
            single_pos_sum = x1+x2 +carry;
            sum.push(single_pos_sum%10);
            carry = single_pos_sum/10;
            i--;
            j--;
        }
        if(carry==1)    //应对case比如‘99+1=100’
            sum.push(carry);
        while(!sum.empty()){
            res.push_back(sum.top()+'0');
            sum.pop();
        }
        return res;        
    }
};