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

    int mySqrt(int x)
    {
        if(x <= 1)
            return x;
        int start = 1, end = x;
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            if(mid <= x/mid)
                start = mid + 1;
            else
                end = mid;
        }
        return start - 1;
    }
};