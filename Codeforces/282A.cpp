#include <iostream>
#include <cstdio>
using namespace std;

char s[4];
int x;
int main(){
    while (fgets(s, sizeof(s), stdin)) {
        x += 44 - s[1];
    }
    cout << x;
}