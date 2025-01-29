#include <iostream>
using namespace std;

char s[4];
int x;
int main(){
    for (gets(s); gets(s); x += 44 - s[1]);
    cout << x;
}