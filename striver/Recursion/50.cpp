#include<bits/stdc++.h>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;  // Base case

        long long exp = abs((long long)n); // Handle INT_MIN case
        double ans = 1.0;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans *= x;
            }
            x *= x;
            exp /= 2;
        }
        
        return n < 0 ? 1.0 / ans : ans;
    }
};
