#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool reorderedPowerOf2(int n) {
            // Step 1: Get digit frequency of input number n
            vector<int> digitCount(10, 0);
            while (n > 0) {
                digitCount[n % 10]++;
                n /= 10;
            }
            
            // Step 2: Check all powers of 2 from 2^0 to 2^30
            for (int i = 0; i <= 30; i++) { // 2^30 is ~10^9
                long long powerOf2 = 1LL << i; // Compute 2^i
                vector<int> powerDigitCount(10, 0);
                
                // Get digit frequency of the current power of 2
                while (powerOf2 > 0) {
                    powerDigitCount[powerOf2 % 10]++;
                    powerOf2 /= 10;
                }
                
                // Compare digit frequencies
                if (digitCount == powerDigitCount) {
                    return true;
                }
            }
            
            return false;
        }
    };