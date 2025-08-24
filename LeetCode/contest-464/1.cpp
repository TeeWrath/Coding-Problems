#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int gcdOfOddEvenSums(int n) {
            int oddsum = 0;
            int evensum = 0;

            for(int i=0;i<n;i++){
                oddsum += 2*i;
                evensum += (2*i) + 1;
            }

            int prevdiv = 1;
            int dividend = max(oddsum,evensum);
            int divisor = min(oddsum,evensum);

            while(divisor != 0){
                prevdiv = divisor;
                divisor = dividend % divisor;
                dividend = prevdiv;
            }

            return prevdiv;
        }
    };