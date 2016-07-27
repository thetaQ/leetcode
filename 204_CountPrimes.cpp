#include <iostream>
using namespace std;

class Solution {
public:

    bool isPrime(int n)
    {
        for(int i = 2; i < n; i++)
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    

    //timeout
    int countPrimes(int n)
    {
        if(n <= 2)
            return 0;
        if(n == 3)
            return 1;
        int count = 1;
        for(int i = 3; i < n; i++)
        {
            if(isPrime(i))
                count ++;
        }
        return count;
    }

    int countPrimes_2(int n)
    {
        if(n <= 2)
            return 0;
        if(n == 3)
            return 1;

        bool isprime[n];
        for(int i = 0; i < n; i++)
            isprime[i] = true;
        isprime[0] = false;
        isprime[1] = false;
        for(int i = 2; i < n; i++)
        {
            for(int k = 2; k * i < n; k++)
            {
                isprime[k*i] = false;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(isprime[i])
                count++;
        }
        return count;
    }
};