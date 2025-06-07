#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool static comp(Item a,Item b){
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1>r2;
}

int fractionalKnapsack(int w, vector<Item> & arr){
    int n = arr.size();
    sort(arr.begin(),arr.end(),comp);

    int curWt =0;
    double finalVal = 0.0;

    for(int i=0; i<n; i++){
        if(curWt + arr[i].weight <= w){
            curWt += arr[i].weight;
            finalVal += arr[i].value;
        }else{
            int remain = w - curWt;
            finalVal += (arr[i].value/(double)arr[i].weight) * (double)remain;
            break;
        }
    }

    return finalVal;
}

int main(){
    vector<Item> arr = {{100,20},{60,10},{120,30}};
    int w = 50;
    cout << fractionalKnapsack(w,arr) << endl;
    return 0;
}