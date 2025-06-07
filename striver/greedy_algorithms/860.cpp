#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
    int fives =0,tens =0;
    for(int i=0; i<n ; i++){
        if(bills[i] == 5) fives++;
        else if(bills[i] == 10){
            tens++;
            if(fives > 0) fives--;
            else return false;
        }else if(bills[i] == 20){
            if(fives > 0 && tens > 0){
                fives--,tens--;
            }else if(fives >= 3)fives -= 3;
            else return false;
        }
    }

    return true;
}

int main(){

    return 0;
}