class Solution {
    public:
        int divide(int dividend, int divisor) {
            // Handle special case: division by 1 or -1
            if (divisor == 1) return dividend;
            if (divisor == -1) {
                if (dividend == INT_MIN) return INT_MAX; // Handle overflow
                return -dividend;
            }
            
            // Handle dividend == 0
            if (dividend == 0) return 0;
            
            // Handle the special case of INT_MIN / -1
            if (dividend == INT_MIN && divisor == -1) return INT_MAX;
            
            // Determine the sign of the result
            bool sign = (dividend < 0) == (divisor < 0);
            
            // Convert to long long to avoid overflow and use absolute values
            long long n = abs((long long)dividend);
            long long d = abs((long long)divisor);
            
            long long quotient = 0;
            while (n >= d) {
                long long temp = d;
                long long count = 1;
                
                // Use bit shifting to find the largest possible divisor
                while (n >= (temp << 1) && (temp << 1) > 0) {
                    temp <<= 1;
                    count <<= 1;
                }
                
                quotient += count;
                n -= temp;
            }
            
            // Apply sign and handle overflow
            quotient = sign ? quotient : -quotient;
            
            // Check for 32-bit integer overflow
            if (quotient > INT_MAX) return INT_MAX;
            if (quotient < INT_MIN) return INT_MIN;
            
            return static_cast<int>(quotient);
        }
    };