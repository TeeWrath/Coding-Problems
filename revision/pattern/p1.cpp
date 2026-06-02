#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1;j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i;j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i;j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i;j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n-i;j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void pattern7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i;j++)
        {
            cout << " ";
        }
        for(int k=1; k<= 2*i-1;k++){
            cout<< "*";
        }
        cout << endl;
    }
}

void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i;j++)
        {
            cout << " ";
        }
        for(int k=0; k< 2*n - (2*i+1);k++){
            cout<< "*";
        }
        cout << endl;
    }
}

void pattern9(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i;j++)
        {
            cout << " ";
        }
        for(int k=1; k<= 2*i-1;k++){
            cout<< "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i;j++)
        {
            cout << " ";
        }
        for(int k=0; k< 2*n - (2*i+1);k++){
            cout<< "*";
        }
        cout << endl;
    }
}

void pattern10(int n){
    for(int i=1; i<= 2*n - 1; i++){
        if(i<=n){
            for(int j=1; j<=i; j++){
                cout << "* ";
            }
        }else{
            for(int j=1; j<= 2*n - i; j++){
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void pattern11(int n){
    bool row=true;
    for(int i=1;i<=n;i++){
        cout<<row;
        bool dig= !row;
        for(int j=2;j<=i;j++){
            cout<<dig;
            dig = !dig;
        }
        cout << endl;
        row = !row;
    }
}

void pattern12(int n){
    for(int i=1;i<=n;i++){
        int spaces = 2*(n-1);
        for(int j=1;j<=i;j++)cout <<j;
        for(int j=1;j<= spaces;j++)cout << " ";
        for(int j=i; j>=1;j--)cout<<j;
        cout << endl;
        spaces -=2;
    }
}

void pattern13(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num<<" ";
            num++;
        }
        cout << endl;
    }
}

void pattern14(int n){
    for(int i=1;i<=n;i++){
        char var = 'A';
        for(int j=1;j<=i;j++){
            cout<<var<<" ";
            var++;
        }
        cout<<endl;
    }
}

void pattern15(int n){
    for(int i=n;i>=1;i--){
        char var = 'A';
        for(int j=1;j<=i;j++){
            cout<<var<<" ";
            var++;
        }
        cout<<endl;
    }
}

void pattern16(int n){
    char var = 'A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<var<<" ";
        }
        var++;
        cout<<endl;
    }
}

// may repeat
void pattern17(int n){
    for(int i=0;i<n;i++){
        char var = 'A';
        for(int j=0;j<= n -i - 1;j++)cout << " ";
        int bp = ((2*i)+1)/2;
        for(int j=1;j<=(2*i)+1;j++){
            cout << var;
            if(j <= bp) var++;
            else var--;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    pattern17(n);
    return 0;
}