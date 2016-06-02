#include<iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int total = (C-A)*(D-B) + (G-E)*(H-F);
        int overlap;
        if(C <= E || A>=G || B >= H || D <= F)
            overlap = 0;
        else
            overlap = (min(C,G)-max(A,E)) * (min(D,H)-max(B,F));
        return total - overlap;
    }
};