#include<bits/stdc++.h>
using namespace std;

// My solution - time inefficient but memory efficient
class Solution
{
public:
    int maxContainers(int n, int w, int maxWeight)
    {
        int c = n * n;
        int t = c;
        int wt = maxWeight;

        while (c > 0 && wt >= 0)
        {
            wt -= w;
            c--;
        }

        if (wt < 0)
            c += 1;
        return t - c;
    }
};

// Most optimal - time efficient but memory inefficient
class Solution
{
public:
    int maxContainers(int n, int w, int maxWeight)
    {
        return min(maxWeight / w, n * n);
    }
};