#include <bits/stdc++.h>
using namespace std;

void swapNums(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

bool checkIthBitIsSet(int n, int i)
{
    // using left shift
    return (n & (1 << i)) == 0 ? false : true;

    // using right shift
    return (n >> i) & 1 == 0 ? false : true;
}

int setIthBit(int n, int i)
{
    return (n | (1 << i));
}

int clearIthBit(int n, int i)
{
    return (n &~ (1 << i));
}

int toggleIthBit(int n, int i)
{
    return (n ^ (1 << i));
}

int rightMostithBit(int n){
    return n & (n-1);
}

bool isPowerOf2(int n){
    return (n & (n-1)) == 0? true:false;
}

int countNoOfSetBits(int n){
    int cnt =0;

    // one approach 
    // while(n != 1){
    //     cnt += n&1;
    //     n = n >> 1;
    // }
    // if(n == 1)cnt++;

    // better approach
    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

bool checkOddEven(int n){
    return n&1;
}

int main()
{
    int a;
    cin >> a;
    // cout << "Numbers before swapping: " << a << " and " << b << endl;
    // swapNums(a, b);
    // cout << "Numbers after swapping: " << a << " and " << b << endl;
    // cout << checkIthBitIsSet(a, b) << endl;
    cout << checkOddEven(a) << endl;
}