class Solution {
public:


    //netow's method
    int mySqrt_2(int x)
    {
        if(x <= 0)
            return 0;
        long long v = x;
        while(v * v > x)
            v = (v + x / v) >> 1;
        return v;
    }
};