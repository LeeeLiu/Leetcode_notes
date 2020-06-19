

[题解](https://www.cnblogs.com/ECJTUACM-873284962/p/6750320.html)


class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    // a bottle with volume of 's' filled with cola 
    // two empty cups with volume of 'n' and 'm'
    // n + m = s
    // Ask if s  can be divided equally by pouring cola between 3 containers?
    // if yes, return the minimum number of times to pour cola, 
    // otherwise return -1.
    int getMinTimes(int s, int n, int m) {
        if(s%2 != 0)
            return -1;
        int res= s/gcd(n,m);
        return res%2==0? res-1: -1;
        
        // Write your code here
    }
};