#include<bits/stdc++.h>
using namespace std;

// Pairs
void explainPair(){
    pair<int, int> p = {1,5};
    cout << p.first << " " << p.second << endl;

    // Nested pair
    pair<int, pair<int, int>> q = {1, {5,2}};
    cout<< q.first << " " << q.second.first << " " << q.second.second << endl;

    // Array of pairs
    pair<int, string> arr[2] = {{1, "Subroto"}, {2,"Shreya"}};
    cout << arr[1].second << endl;
}

// Vectors
void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    // cout << v[1] << endl << v[2];

    // Pair nested in vector
    vector<pair<int, int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(4,5);
    // cout << vec[0].first << endl << vec[0].second << endl << vec[1].first << endl << vec[1].second;

    vector<int> q(10,100);
    // cout << q[0] << endl << q[1] << endl << q[2];

    // Using iterators
    for(vector<int> :: iterator it = q.begin(); it != q.end(); it++){
        // cout << *(it) << " ";
    }

    cout << endl;

    // Another method
    for(auto t : q){
        // cout << t << " ";
    }
}

// List
void explainList(){
    
}

int main(){
    // explainPair();
    explainVector();
    return 0;
}